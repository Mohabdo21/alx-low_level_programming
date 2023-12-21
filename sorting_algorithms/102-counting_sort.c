#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = 0, *count, *output;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum number in the array */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Initialize the count array */
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Store the count of each number */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the count array */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/* Build the output array */
	output = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted elements into the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
