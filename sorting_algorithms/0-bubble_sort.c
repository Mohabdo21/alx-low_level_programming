#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	bool swapped = false;
	size_t i;
	int temp;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = false;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swap */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;

				print_array(array, size);
			}
		}
	} while (swapped);
}
