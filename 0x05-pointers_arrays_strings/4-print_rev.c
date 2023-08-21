#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
	len++;
	s++;
	}

	return (len);
}

/**
 * print_rev - Prints a string in reverse, followed by a new line.
 * @s: Pointer to the input string.
 */

void print_rev(char *s)
{
	int length = _strlen(s);
	int i;

	for (i = length - 1; i >= 0; i--)
	{
	_putchar(s[i]);
	}

	_putchar('\n');
}
