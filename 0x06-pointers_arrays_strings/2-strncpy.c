#include "main.h"
/**
 * _strncpy - Copies a string, using at most n bytes from src.
 * @dest: The destination string to which src will be copied.
 * @src: The source string to be copied to dest.
 * @n: The maximum number of bytes from src to be copied.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
	dest[i] = src[i];
	}

	for (; i < n; i++)
	{
	dest[i] = '\0';
	}

	return (dest);
}
