#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * array_range - Creates an array of integers from min to max
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: A pointer to the newly created array.
 * If min > max or malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int *arr, i;

	if (min > max)
		return (NULL);

	arr = malloc(sizeof(int) * (max - min + 1));

	if (arr == NULL)
		return (NULL);

	for (i = 0; min <= max; i++, min++)
		arr[i] = min;

	return (arr);
}
