#include "main.h"
/**
 * _puts - Prints a string followed by a new line.
 * @str: Pointer to the input string.
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
	_putchar(*str);
	str++;
	}

	_putchar('\n');
}
