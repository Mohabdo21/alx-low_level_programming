#include "main.h"
/**
 * string_toupper - Changes all lowercase letters of a string to uppercase.
 * @str: The string to be modified.
 *
 * Return: A pointer to the resulting modified string.
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
	if (*ptr >= 'a' && *ptr <= 'z')
	{
		*ptr = *ptr - 32;
	}
	ptr++;
	}

	return (str);
}
