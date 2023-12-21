#include "sort.h"


/**
 * radix_sort - sorts an array of integers in ascending order
 * Despcription: is a non-comparative sorting algorithm. It avoids comparison
 * by creating and distributing elements into buckets
 * according to their radix(base)
 * @array: array to sort
 * @size: length of the @array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max, *output;

	if (size < 2)
		return;

	output = malloc(size * sizeof(int));
	max = array[0];

	/* get the max */
	for (i = 1; i < size; i++)
		if (max < array[i])
			max = array[i];

	base_sort(array, output, size, max, 0);

	/* cleanup */
	free(output);
}

/**
 * base_sort - sort array in ascending order using radix sort algo
 * Despcription: instead of using buckets to store our output on each
 * iteration and using a lot of allocation, we use prefix sum technique
 * @input: original array
 * @output: array to store our @input on each round of sort
 * @size: length of the array
 * @max: maximum number in the array
 * @expo: exponent starts from zero, up to the number of digits in @max - 1
 *
 * Return: Nothing
 */
void base_sort(int *input, int *output, size_t size, int max, int expo)
{
	size_t i;
	int bin, prefix_sum[BASE10];

	if (max == 0)
		return;

	/* initialize prefix */
	for (i = 0; i <  BASE10; i++)
		prefix_sum[i] = 0;

	/* counting prefixes */
	for (i = 0; i < size; i++)
	{
		bin = (input[i] / _pow(BASE10, expo)) % BASE10;
		prefix_sum[bin]++;
	}

	/* sum the prefixes */
	for (i = 1; i < BASE10; i++)
		prefix_sum[i] += prefix_sum[i - 1];

	/* fill-in the ouput according to prefix values */
	/* incrementing `i` this way to avoid compiler warning (hence size_t) */
	for (i = size; i-- > 0; )
	{
		bin = (input[i] / _pow(BASE10, expo)) % BASE10;
		output[--prefix_sum[bin]] = input[i];
	}

	/* copy the output to the input */
	for (i = 0; i < size; i++)
		input[i] = output[i];

	print_array(input, size);

	/* clear our prefix */
	for (i = 0; i < BASE10; i++)
		prefix_sum[i] = 0;

	base_sort(input, output, size, max / 10, expo + 1);
}

/**
 * _pow - simple mock implementation of the libc `pow` function
 * @b: the base
 * @e: exponent
 *
 * Return: the power
 */
int _pow(int b, int e)
{
	if (e <= 0)
		return (1);
	if (e == 1)
		return (b);
	return (b * _pow(b, e - 1));
}
