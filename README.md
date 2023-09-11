# Custom-Shell

## ShellEx - Custom Shell

### Description
ShellEx is a custom shell program developed in C. It provides a basic command-line interface that allows you to run shell commands and built-in commands.

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
exit: Exit the shell.  <br />
pid: Print the process ID of the shell.  <br />
ppid: Print the parent process ID of the shell.  <br />
cd <path>: Change the current working directory.  <br />
help: Display a help message with available commands. 

6. For non-built-in commands, you can use standard shell commands. Refer to the manual pages for more information on specific commands:

   ```
   man <command>
   ```

7. To exit the ShellEx program, you can use the exit command or press Ctrl + C.

## my257sh Makefile

### Description
This Makefile is used to compile the `shellex.c` program, a custom shell for the CMSC 257 course. It simplifies the process of building the shell executable.

### Requirements
To use this Makefile, you need the following:

- GCC (GNU Compiler Collection)
- The `shellex.c` source file.
- The `csapp.c` library (presumably required by `shellex.c`).

### Usage
1. Clone the repository containing the `Makefile` and your source code to your local machine:

   ```shell
   git clone https://github.com/yourusername/my257sh.git
   ```

2. Navigate to the project directory:
   ```shell
   cd my257sh
   ```

3. To compile the 'shellex.c' program, simply run the following command:
   ```shell
   make
   ```
   This command will use the Makefile rules to build the 'sh257' executable.

4. Once the compilation is successful, you can run the 'sh257' executable:
    ```shell
   ./sh257
    ```
5. You can use the custom shell for various shell commands and built-in commands, as described in the shellex.c README.

6. To clean up and remove the sh257 executable, use the following command:
   ```shell
   make clean
   ```
   
