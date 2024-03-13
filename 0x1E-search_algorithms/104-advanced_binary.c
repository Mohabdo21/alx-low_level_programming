#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @low: The first index of the subarray to print
 * @high: The last index of the subarray to print
 *
 * Return: No return value. Function is void.
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");

	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);

		if (i < high)
			printf(", ");
	}

	printf("\n");
}

/**
 * binary_search_recursive - Recursively applies binary search algorithm
 * @array: The array to search
 * @low: The first index of the subarray to search
 * @high: The last index of the subarray to search
 * @value: The value to search for
 *
 * Return: The index where value is located,
 * or -1 if not found or array is NULL
 */
int binary_search_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (high >= low)
	{
		print_array(array, low, high);

		mid = low + (high - low) / 2;

		if (array[mid] == value)
		{
			if (mid == low || array[mid - 1] < value)
				return (mid);
			else
				return (binary_search_recursive(array, low, mid, value));
		}

		if (array[mid] > value)
			return (binary_search_recursive(array, low, mid, value));

		return (binary_search_recursive(array, mid + 1, high, value));
	}

	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located,
 * or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
