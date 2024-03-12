#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located,
 * or -1 if value is not present
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump;
	size_t i, j;

	if (!array)
		return (-1);

	/* Calculate the jump interval */
	jump = sqrt(size);

	/* Find the block where the element may be present */
	for (i = 0; i < size; i += jump)
	{
		if (array[i] >= value)
			break;
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	}

	/* Perform a linear search within the identified block */
	j = i < jump ? 0 : i - jump;
	printf("Value found between indexes [%lu] and [%lu]\n", j, i);
	for (; j <= i && j < size; j++)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}

	return (-1);
}
