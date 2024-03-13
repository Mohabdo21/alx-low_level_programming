#include "search_algos.h"

/**
* interpolation_search - Searches for a value in a sorted array of integers
* @array: Pointer to the first element of the array to search in
* @size: Number of elements in array
* @value: Value to search for
*
* Return: The index where the valule is located, or -1 if value not present
*/
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (!array)
		return (-1);

	/* Continue searching while value is within the range of the array */
	while ((array[high] != array[low]) && (value >= array[low]) &&
		(value <= array[high]))
	{
		/* Calculate the position using the interpolation formula */
		pos = low + (((double)(high - low) /
			(array[high] - array[low])) * (value - array[low]));

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);

		/* value is greater, move the low index to the right */
		if (array[pos] < value)
			low = pos + 1;
		else
			/* value is smaller, move the high index to the left */
			high = pos - 1;
	}

	if (value == array[low])
		return (low);

	/* value is not found */
	pos = low + (((double)(high - low) /
		(array[high] - array[low])) * (value - array[low]));

	printf("Value checked array[%lu] is out of range\n", pos);

	return (-1);
}
