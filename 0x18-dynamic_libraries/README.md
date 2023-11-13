# 0x18. C - Dynamic Libraries

This project is part of the Alx - SE curriculum of software engineering. The main objective is to understand and implement dynamic libraries in C.

## Learning Objectives

- Understand what a dynamic library is, how it works, how to create one, and how to use it.
- Learn about the environment variable `$LD_LIBRARY_PATH` and how to use it.
- Understand the differences between static and shared libraries.
- Basic usage of `nm`, `ldd`, `ldconfig`.

### What is a dynamic library, how does it work, how to create one, and how to use it

A dynamic library is a collection of object files that can be linked to a program at runtime. The library remains separate from the executable file and can be used by multiple programs. To create a dynamic library in C, you compile your C code into object files with the `-fPIC` flag, then use the `-shared` flag to create the library from the object files. To use a dynamic library, you link it to your program at compile time with the `-l` flag.

### What is the environment variable $LD_LIBRARY_PATH and how to use it

`$LD_LIBRARY_PATH` is an environment variable that specifies a list of directories where the dynamic linker should look for dynamic libraries at runtime. You can add a directory to this variable with the command `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/library`.

### What are the differences between static and shared libraries

Static libraries are linked to the program at compile time and become part of the executable file. Each program using a static library has its own copy of the library's code. Dynamic libraries, on the other hand, are linked at runtime and remain separate from the executable. They can be shared by multiple programs, which can save memory.

### Basic usage nm, ldd, ldconfig

`nm` is a tool that displays the symbol table of a given object file. `ldd` prints the shared libraries required by a program. `ldconfig` creates the necessary links and cache (for use by the run-time linker) to the most recent shared libraries found in the directories specified in the command line, in the file `/etc/ld.so.conf`, and in the trusted directories.
