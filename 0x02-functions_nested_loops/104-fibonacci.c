#include <stdio.h>
#include <stdint.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	__uint128_t n1 = 1;
	__uint128_t n2 = 2;
	__uint128_t next;
	__uint128_t lower_mask;	
	int count;

	printf("%lu, %lu", (unsigned long)n1, (unsigned long)n2);

	lower_mask = ((__uint128_t)1 << 64) - 1;

	for (count = 2; count < 98; count++)
	{
	next = n1 + n2;

	printf(", %lu", (unsigned long)(next >> 64));
	printf("%016lu", (unsigned long)(next & lower_mask));


	n1 = n2;
	n2 = next;
	}

	printf("\n");

	return (0);
}
