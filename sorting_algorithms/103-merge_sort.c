#include "sort.h"

/**
 * merge_sort - sort array using top down techinque
 * @array: array to sort
 * @size: lehgth of the @arry
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (size < 2)
		return;

	b = malloc(sizeof(int) * size);

	td_split(array, 0, size, b);

	free(b);
}


/**
 * td_merge - merge R and L halves sorted
 * Description: using top down merge
 * @a: oringinal array
 * @b: array holds the sorted halves
 * @start: 1st position in the half
 * @mid: 1st pos for the L half or last pos for R half
 * @end: last position in the half (L or R)
 *
 * Return: Nothing
 */
void td_merge(int *b, int start, int mid, int end, int *a)
{
	int i = start, j = mid, k = start, ignore_L = 0, ignore_R = 0;

	printf("Merging...\n");
	for (k = start; k < end; k++)
	{
		/* sort half (L or R) */
		if (i < mid && (j >= end || a[i] <= a[j]))
			b[k] = a[i++];
		else
			b[k] = a[j++];

		if (k < mid)
		{
			if (!ignore_L)
				printf("[left]: ");
			ignore_L = 1;
			printf("%i%s", a[k], k < mid - 1 ? ", " : "\n");
		}
		else
		{
			if (!ignore_R)
				printf("[right]: ");
			ignore_R = 1;
			printf("%i%s", a[k], k < end - 1 ? ", " : "\n");
		}
	}

	/* merge the sorted back to original array */
	for (k = start; k < end; k++)
	{
		a[k] = b[k];
		if (k == start)
			printf("[Done]: ");
		printf("%i%s", b[k], k < end - 1 ? ", " : "\n");
	}
}

/**
 * td_split - split the array into 2 halves
 * @a: oringinal array
 * @b: array holds the sorted half
 * @start: 1st position in the half (L or R)
 * @end: last position in the half (L or R)
 *
 * Return: Nothing
 */
void td_split(int *a, int start, int end, int *b)
{
	int mid;

	if (end - start <= 1)
		return;

	mid = (end + start) / 2;

	/* insure L is always <= R */
	td_split(a, start, mid, b); /* L half */
	td_split(a, mid, end, b); /* R half */
	td_merge(b, start, mid, end, a);
}
