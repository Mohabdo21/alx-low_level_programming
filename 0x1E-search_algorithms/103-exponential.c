#include "search_algos.h"

/**
 * binary_search_e - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * @index_offset: deviation if the index
 * Return: The index where value is located, or -1 if value is not present
 */
int binary_search_e(int *array, size_t size, int value, size_t index_offset)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid;
	size_t i;

	if (!array)
		return (-1);

	while (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
				printf(", ");
			else
				printf("\n");
		}
		mid = (low + high) / 2;
		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid + index_offset);
	}
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t lower_bound = 0;
	size_t search_size;

	if (!array || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		lower_bound = bound;
		bound *= 2;
	}

	if (bound >= size)
		bound = size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", lower_bound, bound);
	search_size = bound < size ? bound - lower_bound + 1 : size - lower_bound;
	return (binary_search_e(array + lower_bound,
						 search_size, value, lower_bound));
}
