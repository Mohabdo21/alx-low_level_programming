#include "main.h"
/**
 * _strstr - Locate substring
 * @haystack: Pointer to the string to be searched
 * @needle: Pointer to the substring to be found
 *
 * Return: A pointer to the beginning of the located substring or
 * NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	if (!needle)
		return (haystack);

	while (*haystack)
	{
		char *h = haystack;
		char *n = needle;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		if (!*n)
			return (haystack);

		haystack++;
	}

	return (NULL);
}
