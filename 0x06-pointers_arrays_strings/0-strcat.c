#include "main.h"
/**
 * _strcat - Concatenating two strings
 * @dest: Destenation string to src will be appended
 * @src: The source string to be appended to dest
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
