# Custom-Shell

## ShellEx - Custom Shell for CMSC 257

### Description
ShellEx is a custom shell program developed in C for the CMSC 257 course. It provides a basic command-line interface that allows you to run shell commands and built-in commands.

### Requirements
To compile and run ShellEx, you need the following:

- GCC (GNU Compiler Collection)
- Linux/Unix-like operating system
- The provided `csapp.h` library (make sure it's in the same directory as `shellex.c`)

### Usage
1. Clone the repository to your local machine:

   ```
   git clone https://github.com/yourusername/shellex.git
   ```

2. Navigate to the project directory:

   ```
   cd shell ex
   ```

3. Compile the ShellEx program:

   ```
   gcc -o shellex shellex.c -lpthread
   ```

4. Run the ShellEx program:

   ```
   ./shellex
   ```

5. You can use various shell commands and built-in commands, including:

exit: Exit the shell.
pid: Print the process ID of the shell.
ppid: Print the parent process ID of the shell.
cd <path>: Change the current working directory.
help: Display a help message with available commands.

6. For non-built-in commands, you can use standard shell commands. Refer to the manual pages for more information on specific commands:

   ```
   man <command>
   ```

7. To exit the ShellEx program, you can use the exit command or press Ctrl + C.
