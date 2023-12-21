#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Start with the largest gap using the Knuth sequence */
	for (gap = 1; gap < size; gap = gap * 3 + 1)
		;

	/* Decrease the gap and sort the elements */
	for (gap /= 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
