#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid;
	int res;

	if (!array || size == 0)
		return (-1);

	print_array(array, size);

	if (size == 1 && array[0] != value)
		return (-1);

	mid = (size - 1) / 2;
	if (array[mid] == value)
		return (mid);

	if (array[mid] > value)
		return (binary_search(array, mid + 1, value));

	res = binary_search(array + mid + 1, size - mid - 1, value);
	if (res == -1)
		return (-1);

	return (res + mid + 1);
}
