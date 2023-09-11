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

   ```shell
   cd shell ex
   ```

3. Compile the ShellEx program:

   ```shell
   gcc -o shellex shellex.c -lpthread
   ```

4. Run the ShellEx program:

   ```shell
   ./shellex
   ```

5. You can use various shell commands and built-in commands, including:
exit: Exit the shell.  <br />
pid: Print the process ID of the shell.  <br />
ppid: Print the parent process ID of the shell.  <br />
cd <path>: Change the current working directory.  <br />
help: Display a help message with available commands. 

6. For non-built-in commands, you can use standard shell commands. Refer to the manual pages for more information on specific commands:

   ```shell
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

## CSAPP - C Server Application Package

### Description
`csapp.h` is a header file containing various prototypes and definitions useful for network programming in C. It is often used in conjunction with the CS:APP (Computer Systems: A Programmer's Perspective) book and provides wrappers and utilities for system calls, socket programming, threading, and more.

### Requirements
To use `csapp.h` in your C projects, you need the following:

- A C compiler (e.g., GCC)
- A Unix-like operating system (e.g., Linux or macOS)

### Usage
1. Clone the repository containing `csapp.h` to your local machine:

   ```shell
   git clone https://github.com/yourusername/csapp.git
   ```

2. Include csapp.h in your C source code by adding the following line at the top of your file:
   ```shell
   #include "csapp.h"
   ```

3. Write and compile your C program using the provided functions and definitions from csapp.h. Refer to the CS:APP book or online documentation for details on how to use these functions effectively.

4. Compile your C program as usual. For example:
   ```shell
   gcc -o myprogram myprogram.c -lpthread
   ```

5. Run your compiled program:
   ```shell
   ./myprogram
   ```
   
6. Be sure to read the CS:APP book or the relevant documentation for csapp.h to understand how to use the various functions and utilities it provides effectively.
   
   
