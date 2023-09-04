#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of the program
 * @ac: the argument count
 * @av: an array of strings
 *
 * Return: a pointer to the concatenated string, else (NULL)
 */
char *argstostr(int ac, char **av)
{
	int total_length;
	int i;
	int j;
	char *concatenated;
	int position;

	if (ac == 0 || av == NULL)
	return (NULL);

	total_length = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			total_length++;
			j++;
		}
		total_length++;
	}
	concatenated = malloc(total_length + 1);

	if (concatenated == NULL)
	return (NULL);

	position = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			concatenated[position++] = av[i][j];
			j++;
		}
		concatenated[position++] = '\n';
	}
	concatenated[position] = '\0';
	return (concatenated);
}
