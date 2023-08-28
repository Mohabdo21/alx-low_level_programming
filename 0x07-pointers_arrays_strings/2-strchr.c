#include "main.h"
/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string to be searched.
 * @c: Character to be located.
 *
 * Return: A pointer to the first occurrence of the char c
 * in the str s,or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
	if (*s == c)
	{
		return (s);
	}
	s++;
	}

	if (*s == c)
	{
	return (s);
	}

	return (NULL);
}
