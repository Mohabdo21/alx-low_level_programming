#!/bin/bash

# Compile all .c files into position-independent code and create dynamic library
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -fPIC -c *.c
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o
