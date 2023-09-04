#include "main.h"
#include <stdlib.h>
/**
 * str_concat - Function that concatenate two strings
 * @s1: A pointer to the first string
 * @s2: A pointer to the second string
 *
 * Return: a Pointer to the newly allocated space contained s1
 * & s2, else (NULL)
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;
	char *concatonated;

	len1 = 0;
	len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
	{
		len1++;
	}

	while (s2[len2] != '\0')
	{
		len2++;
	}

concatonated = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	if (concatonated == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		concatonated[i] = s1[i];
	}

	for (j = 0; j < len2; j++)
	{
		concatonated[len1 + j] = s2[j];
	}

	return (concatonated);
}
