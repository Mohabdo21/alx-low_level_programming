#include "main.h"
#include <stdlib.h>
/**
 * _strdup - Returns a pointer to newly allocated space contains
 * a copy of the sting that given as argument
 * @str: Given string
 * Return: Returns pointer to duplicated string, else "NULL"
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length;
	unsigned int i;

	length = 0;

	if (str == NULL)
	return (NULL);


	while (str[length] != '\0')
	{
		length++;
	}

	duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
	return (NULL);

	for (i = 0; i <= length; i++)
	{
	duplicate[i] = str[i];
	}

	return (duplicate);
}
