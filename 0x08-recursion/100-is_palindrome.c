#include "main.h"
/**
 * _strlen_recursion - Compute the lenght of a string
 * @s: Input string
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome - Checks if the given strings are palindrome
 *
 * @s: Pointer to string to be checked
 *
 * Return: 1 if a String is Palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	int length = _strlen_recursion(s);

	return (check_palindrome(s, 0, (length - 1)));
}

/**
 * check_palindrome - Helper function to check the string
 * @s: The string to check
 * @start: The starting index
 * @end: The ending index
 *
 * Return: 1 if s is a palindrome, else 0
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome(s, start + 1, end - 1));
}
