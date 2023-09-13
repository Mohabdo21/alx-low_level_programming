#include "function_pointers.h"
/**
 * int_index - Searches for an integer in an array.
 * @array: The array to search through
 * @size: The number of elements in the array
 * @cmp: A pointer to the function used to compare values
 *
 * Return: The index of the first element for which cmp returns non-zero.
 * If no element matches or size is <= 0, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		if (size <= 0)
		return (-1);

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			return (i);
		}
	}

	return (-1);
}
