#include "sort.h"



/**
 * bitonic_sort - sort in ascending order using Bitonic algo.
 * @array: array to sort
 * @size: lenght of an array
 *
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	bsort(array, 0, size, 1, size);
}
/**
 * bsort - sort in ascending order using Bitonic algo.
 * @arr: array to sort
 * @low: first index in the half
 * @count: size of half
 * @size: lenght of an array
 * @dir: dircetion (increasing/decreasing)
 *
 * Return: Nothing
 */
void bsort(int *arr, int low, size_t count, int dir, size_t size)
{
	int k = count / 2;

	if (count > 1)
	{
		printf("Merging [%li/%li] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
		print_array(arr + low, count);
		bsort(arr, low, k, 1, size);
		bsort(arr, low + k, k, 0, size);
		bmerge(arr, low, count, dir, size);
	}
}
/**
 * bmerge - merge bitonically.
 * @arr: array to sort
 * @low: first index in the half
 * @count: size of half
 * @size: lenght of an array
 * @dir: dircetion (increasing/decreasing)
 *
 * Return: Nothing
 */
void bmerge(int *arr, int low, size_t count, int dir, size_t size)
{
	size_t i, k;

	for (k = count / 2; k > 0; k--)
	{
		for (i = low; i < count - k + low; i++)
		{
			if (dir == (arr[i] > arr[i + k] ? 1 : 0))
			{
				arr[i] ^= arr[i + k];
				arr[i + k] ^= arr[i];
				arr[i] ^= arr[i + k];

			}
		}
	}
	printf("Result [%li/%li] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
	print_array(arr + low, count);
}

#if 0

/**
 * bs_bitwise - bitonic sort using bit-wise manimulation
 * @array: length
 * @size: length
 *
 * Return: Nothing
 */
void bs_bitwise(int *array, size_t size)
{
	size_t i, j, k, l;
	int m;

	if (size < 2)
		return;
	for (k = 2; k <= size; k *= 2)
		for (j = k / 2; j > 0; j /= 2)
			for (i = 0; i < size; i++)
			{
				l = i ^ j;
				if (l > i)
				{
					m = i & k;
					if ((m == 0 && array[i] > array[l]) ||
							(m != 0 && array[i] < array[l]))
					{
						array[i] ^= array[l];
						array[l] ^= array[i];
						array[i] ^= array[l];
						printf("k = %li, j = %li\n", k, j);
					}
				}
			}
}
#endif
