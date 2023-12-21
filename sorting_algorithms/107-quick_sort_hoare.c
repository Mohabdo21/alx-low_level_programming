#include "sort.h"


/**
 * quick_sort_hoare - sort using Hoare partition
 * @array: array to sort
 * @size: lenght of an array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	qsort_Hoare(array, 0, size - 1, size);
}

/**
 * qsort_Hoare - sort ascending recursively
 * Description: using Hoare partitioning
 * @arr: array of int
 * @lo: smallest index corresponds to array half
 * @hi: biggest index corresponds to the half
 * @size: legnth of array
 *
 * Return: Nothing
 */
void qsort_Hoare(int *arr, int lo, int hi, size_t size)
{
	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		int pidx = partition_Hoare(arr, lo, hi, size);

		/* pivot is included */
		qsort_Hoare(arr, lo, pidx, size);/* left */
		qsort_Hoare(arr, pidx + 1, hi, size); /* right */
	}
}

/**
 * partition_Hoare - parition the array to determine the pivot
 * @arr: array of int
 * @lo: smallest index corresponds to array half
 * @hi: biggest index corresponds to the half
 * @size: legnth of array
 *
 * Return: pivot index
 */
int partition_Hoare(int *arr, int lo, int hi, size_t size)
{
	int i = lo - 1, j = hi + 1, pivot = arr[hi];

	/**
	 * ifinite loop that breaks out when there's a collision
	 * between `i`, and `j`.
	 * incrementing `i` until it points to an element > pivot
	 * decrementing `j` unitl it points to an element < pivot
	 */
	while (-1)
	{
		while (arr[++i] < pivot)
			;
		while (arr[--j] > pivot)
			;
		if (i >= j)
			return (i - 1);

		arr[i] ^= arr[j];
		arr[j] ^= arr[i];
		arr[i] ^= arr[j];

		print_array(arr, size);
	}
}
