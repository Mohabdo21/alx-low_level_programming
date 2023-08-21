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
 * rev_string - Reverses a string.
 * @s: Pointer to the input string.
 */
void rev_string(char *s)
{
	int length = _strlen(s);
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
	char temp = s[start];

	s[start] = s[end];
	s[end] = temp;

	start++;
	end--;
	}
}
