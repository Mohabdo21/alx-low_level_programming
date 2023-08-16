#include <stdio.h>
/**
 * print_fibonacci - Prints Fibonacci numbers up to a given value.
 * @n: The number of Fibonacci numbers to print.
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
/**
 * main - The entry point of the program.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_fibonacci(50);
	return (0);
}
