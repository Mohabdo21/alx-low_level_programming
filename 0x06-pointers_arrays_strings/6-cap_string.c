#include "main.h"
/**
 * cap_string - capitalize the first character of each word
 *@str: The String of characters
 * Return: Capitalized Charachter
 */

char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
	if (i == 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	} else
	{
		if (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n' ||
				str[i - 1] == ',' || str[i - 1] == ';' || str[i - 1] == '.' ||
				str[i - 1] == '!' || str[i - 1] == '?' ||
				str[i - 1] == '"' || str[i - 1] == '(' || str[i - 1] == ')' ||
				str[i - 1] == '{' || str[i - 1] == '}')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
			}
		}
	}
	i++;
	}

	return (str);
}
