#include "main.h"
/**
 * reverse_array - Reverses the content of an array of integers.
 * @a: An array of integers to be reversed.
 * @n: The number of elements in the array.
 */
void reverse_array(int *a, int n)
{
	int start = 0;
	int end = n - 1;
	int temp;

	while (start < end)
	{
	temp = a[start];
	a[start] = a[end];
	a[end] = temp;

	start++;
	end--;
	}
}
