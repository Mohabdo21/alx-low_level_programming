#include "main.h"
#include <stdlib.h>
/**
 * create_array - function creats an array of chars
 * Return: a pointer to the array ,else "NULL"
 * @size: size for desired array
 * @c: character to fill the array with
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	if (size == 0)
		return (NULL);

	array = (char *)malloc(size * sizeof(char));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);
}
