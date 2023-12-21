#!/bin/bash

# List of possibly used forbidden functions
forbidden=("printf" "puts" "sprintf" "fprintf" "scanf" "fscanf" "sscanf" "getchar" "gets" "putchar" "puts" "fopen" "fclose" "fread" "fwrite" "strcat" "strncat" "strcpy" "strncpy" "strchr" "strrchr" "strcmp" "strncmp" "strstr" "strlen" "strdup" "strndup" "memset" "memcpy" "memmove" "memcmp" "atoi" "atol" "atoll" "itoa" "strtol" "strtoll" "strtod" "strtof" "strtold" "malloc" "calloc" "realloc" "free" "qsort" "bsearch" "exit" "abort")

# ANSI escape codes for colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Scan each .c & .h files
for file in *.{c,h}
do
    # Skip the file if it is print_array.c, print_list.c or ends with main.c
    if [[ "$file" == "print_array.c" || "$file" == "print_list.c" || "$file" == *main.c ]]; then
        continue
    fi

    echo -n "Scanning file: $file... "
    contains_forbidden=false
    for func in "${forbidden[@]}"
    do
        # Use grep to search for the function
        if grep -q "$func" "$file"; then
            contains_forbidden=true
            echo -e "${RED}Forbidden function found: $func${NC}"
        fi
    done

    if ! $contains_forbidden; then
        echo -e "${GREEN}No forbidden functions found${NC}"
    fi

    # Check for Betty style errors
    echo -n "Checking for Betty style errors in $file... "
    if betty "$file" >/dev/null 2>&1; then
        echo -e "${GREEN}No Betty style errors found${NC}"
    else
        betty_errors=$(betty "$file" 2>&1)
        echo -e "${RED}Betty style errors found:\n$betty_errors${NC}"
    fi
done
