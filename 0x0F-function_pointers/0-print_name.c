#include "function_pointers.h"
#include <stdio.h>
/**
 * print_name - prints a name using a given function
 * @name: The name to print
 * @f: A function pointer that determines how to print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
