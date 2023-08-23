#include "main.h"
/**
 * _strncat - Concatenatines two strings, using at most n bytes from src.
 * @dest: Destination string to which src will be appended
 * @src: Source string to be appended to dest
 * @n: Maximum number of bytes from src
 *
 * Return: A pointer to teh resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src && n > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}

	*ptr = '\0';

	return (dest);
}
