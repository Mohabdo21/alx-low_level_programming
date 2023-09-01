#!/bin/bash

# Create Object files:
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Generate Static library:
ar -rc liball.a *.o

# Indexing library:
ranlib liball.a
