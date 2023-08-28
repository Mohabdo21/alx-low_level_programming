#include <stdio.h>
#include "main.h"
/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to the matrix (2D array) of integers.
 * @size: Size of the matrix (number of rows/columns).
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int sum_diag1 = 0;
	int sum_diag2 = 0;
	int index_diag1;
	int index_diag2;

	int i;

	for (i = 0; i < size; i++)
	{
	index_diag1 = i * size + i;
	index_diag2 = (i + 1) * size - (i + 1);

	sum_diag1 += a[index_diag1];
	sum_diag2 += a[index_diag2];
	}

	printf("%d, %d\n", sum_diag1, sum_diag2);
}
