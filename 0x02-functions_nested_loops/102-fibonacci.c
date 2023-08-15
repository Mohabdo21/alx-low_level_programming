#include <stdio.h>
/**
 * main - The Entry point of the program
 *
 * Return: 0 Always (Success)
 */
void print_fibonacci(int n)
{
	unsigned long a = 1;
	unsigned long b = 2;
	unsigned long next;
	int i;

	printf("%lu, %lu", a, b);

	for (i = 2; i < n; i++)
	{
	next = a + b;
	printf(", %lu", next);
	a = b;
	b = next;
	}
	printf("\n");
}

int main(void)
{
	print_fibonacci(50);
	return (0);
}
