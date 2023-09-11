////////////////////////////////////////////////////////////////////////
////
//// File           : shellex.c
//// Description    : shellex source file for project3
//// Author         : ***Cesar Colato***
//// Date           : ***4/28/2023***
//// Notes          : ***N/A

/* $begin shellmain */
#include "csapp.h"
#define MAXARGS 128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

// global variable for storing user shell prompt
char *globalPrompt = "my257sh";

// handle ctrl-c interrupt
void signal_catchfunc(int signal)
{
    printf("\n%s> ", globalPrompt);
    fflush(stdout);
    return;
}

int main(int argc, char *argv[])
{
    char cmdline[MAXLINE]; /* Command line */

    if (argc == 2)
    {
        printf("%s -p <prompt>\n", argv[0]);
        fflush(stdout);
        exit(0);
    }

    if (argc == 3)
    {
        if (strcmp(argv[1], "-p"))
        {
            printf("%s -p <prompt>\n", argv[0]);
            fflush(stdout);
            exit(0);
        }
        globalPrompt = argv[2];
    }

    signal(SIGINT, signal_catchfunc);

    while (1)
    {
        /* Read */
        printf("%s> ", globalPrompt);
        fflush(stdout);
        Fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);

        /* Evaluate */
        eval(cmdline);
    }
}
/* $end shellmain */

// display the help message
void help()
{
    printf("**********************************************************************\n");
    fflush(stdout);
    printf("A Custom Shell for CMSC 257\n");
    fflush(stdout);
    printf("Developer Name: Cesar Colato\n");
    fflush(stdout);
    printf("Usage:\n");
    fflush(stdout);
    printf("Syntax: shellex -p <prompt>\n");
    fflush(stdout);
    printf("**********************************************************************\n");
    fflush(stdout);
    printf("BUILTIN COMMANDS:\n");
    printf("pid: Print the process ID of the shell.\n");
    fflush(stdout);
    printf("ppid: Print the parent process ID of the shell.\n");
    fflush(stdout);
    printf("cd <path>: Print the current working directory or change the current working directory.\n");
    fflush(stdout);
    printf("exit: Exit the shell.\n");
    fflush(stdout);
    printf("help: Display this help message.\n");
    fflush(stdout);
    printf("SYSTEM COMMANDS:\n");
    fflush(stdout);
    printf("For more information on a specific command, use the command 'man <command>'.\n");
    fflush(stdout);
    printf("Note: For non-built-in commands, please refer to the manual pages by typing 'man <command>'.\n");
    fflush(stdout);
    return;
}

/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline)
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return; /* Ignore empty lines */

    if (!builtin_command(argv))
    {
        if ((pid = Fork()) == 0)
        { /* Child runs user job */
            if (execvp(argv[0], argv) < 0)
            {
                printf("%s: Command not found.\n", argv[0]);
                fflush(stdout);
                exit(1);
            }
        }
        /* Parent waits for job to terminate */
        if (!bg)
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                unix_error("waitfg: waitpid error");

            // Check if the process exited normally
            if (WIFEXITED(status))
            {
                int exitStatus = WEXITSTATUS(status);
                // Print the exit status only if it's a non-built in command
                if (WIFEXITED(status))
                {
                    int exitStatus = WEXITSTATUS(status);
                    printf("Process exited with status code %d\n", exitStatus);
                    fflush(stdout);
                }
            }
            // Check if the process was terminated by a signal
            else if (WIFSIGNALED(status))
            {
                printf("Process terminated by signal %d\n", WTERMSIG(status));
                fflush(stdout);
            }
        }
        else
            printf("%d %s", pid, cmdline);
        fflush(stdout);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "exit")) /* quit command */
    {
        int ret = raise(SIGTERM);

        if (ret != 0)
        {
            printf("Unable to terminate program using raise system call.'n");
            fflush(stdout);
            exit(0);
        }
    }
    // get process id
    else if (!strcmp(argv[0], "pid")) 
    {
        printf("%d\n", getpid());
        fflush(stdout);
        return 1;
    }
    // get parent process id
    else if (!strcmp(argv[0], "ppid")) 
    {
        printf("%d\n", getppid());
        fflush(stdout);
        return 1;
    }
    //get help
    else if (!strcmp(argv[0], "help")) 
    {
        help();
        return 1;
    }
    // get process id
    else if (!strcmp(argv[0], "cd")) 
    {
        if (argv[1] == NULL)
        {
            char cwd[100];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                printf("Current dir: %s\n", cwd);
                fflush(stdout);
            }
            else
            {
                printf("getcwd() error");
                fflush(stdout);
                return 1;
            }
        }
        else if (argv[1] != NULL)
        {
            chdir(argv[1]);
        }
        return 1;
    }
    if (!strcmp(argv[0], "&")) /* Ignore singleton & */
        return 1;
        // not a built in command
    return 0; /* Not a builtin command */
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv)
{
    char *delim; /* Points to first space delimiter */
    int argc;    /* Number of args */
    int bg;      /* Background job? */

    buf[strlen(buf) - 1] = ' ';   /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
        buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' ')))
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0) /* Ignore blank line */
        return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc - 1] == '&')) != 0)
        argv[--argc] = NULL;

    return bg;
}
/* $end parseline */
