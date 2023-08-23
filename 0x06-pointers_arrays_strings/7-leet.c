#include "main.h"
/**
 * leet - Function that convert text to leet (1337) style
 * @str: The string to convert to leet style
 * Return: Converted string to leet style
 */
char *leet(char *str)
{
	char conv_to_leet[] = "aAeEoOtTlL";
	char leet_rep_chars[] = "4433007711";
	char *ptr = str;
	int i, j;

	for (i = 0; str[i]; i++)
	{
	for (j = 0; conv_to_leet[j]; j++)
		{
		if (str[i] == conv_to_leet[j])
		{
			str[i] = leet_rep_chars[j];
			break;
		}
		}
	}

	return (ptr);
}
