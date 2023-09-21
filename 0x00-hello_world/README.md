Project:
0x00. C - Hello, World
C Programming - A Brief Overview
--------------------------------

C programming is awesome for several reasons:

-   **Efficiency:** C is known for its high-level control over hardware, making it efficient for system-level programming.
-   **Portability:** Code written in C can be compiled for various platforms with minimal changes.
-   **Powerful Libraries:** C has a rich library of functions and libraries for various purposes.
-   **Low-Level Manipulation:** It allows for direct memory manipulation, which is useful for systems programming.

Inventor of C
-------------

C programming language was invented by **Dennis Ritchie**.

Dennis Ritchie, Brian Kernighan, and Linus Torvalds
---------------------------------------------------

-   **Dennis Ritchie:** Inventor of the C programming language and one of the pioneers in the development of Unix.
-   **Brian Kernighan:** Co-author of the book "The C Programming Language" and a notable figure in the world of computer science.
-   **Linus Torvalds:** Creator of the Linux operating system.

Compiling a C Program with `gcc`
--------------------------------

When you type `gcc main.c`, the GCC (GNU Compiler Collection) compiles the `main.c` source code file and produces an executable binary file named `a.out` by default.

Entry Point and `main` Function
-------------------------------

In C, the **entry point** is the point at which program execution begins. The `main` function serves as the entry point in C programs. It is where the program starts executing.

Printing Text with `printf`, `puts`, and `putchar`
--------------------------------------------------

-   `printf`: Used for formatted output. It allows you to print text with various formatting options.
-   `puts`: Outputs a string followed by a newline character.
-   `putchar`: Outputs a single character.

Getting the Size of a Specific Type with `sizeof`
-------------------------------------------------

You can use the `sizeof` unary operator to determine the size (in bytes) of a specific data type. For example, `sizeof(int)` will give you the size of an `int` in bytes.

Compiling with `gcc`
--------------------

To compile a C program with `gcc`, use the following command:


````shell
gcc source_file.c -o output_executable
````
Default Program Name
--------------------

The default program name when compiling with `gcc` is `a.out`.

Official C Coding Style and `betty-style`
-----------------------------------------

The official C coding style is often associated with the "C Standard" or "ANSI C" style guide. To check your code with `betty-style`, you can use the following command:



````shell
betty your_code.c
````
Finding the Right Header for Standard Library Functions
-------------------------------------------------------

You can find the right header to include by referring to the documentation or by using common headers such as `<stdio.h>` for input and output functions.

Main Function and Return Value
------------------------------

The `main` function influences the return value of the program. By convention, a return value of `0` typically indicates a successful execution, while a non-zero value indicates an error or abnormal termination.
