#include <stdio.h>

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int i, j, n;

	for (i = 0; i < 10; i++)
	{
	for (j = 0; j < 10; j++)
	{
		n = i * j;
		printf(" %d ", n);
	}
	printf("\n");
	}
}
