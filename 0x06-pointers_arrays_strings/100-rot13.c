#include "main.h"
/**
 * rot13 - Function that convert text to Rot13 Code
 * @str: The string to convert to Rot13 code
 * Return: Converted string syphred in Rot13 code
 */
char *rot13(char *str)
{
	char conv_to_rot13[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13_chars[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	int i, j;

	for (i = 0; str[i]; i++)
	{
	for (j = 0; conv_to_rot13[j]; j++)
		{
		if (str[i] == conv_to_rot13[j])
		{
			str[i] = rot13_chars[j];
			break;
		}
		}
	}

	return (str);
}
