#include "main.h"
/**
 * print_number - a function that prints an integer (recursion)
 * @n: number to print
 */
void print_number(int n)
{
	unsigned int number;
	int divisor = 1;

	if (n < 0)
	{
		_putchar('-');
		number = -n;
	}
	else
	{
		number = n;
	}
	while (number / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor != 0)
	{
		_putchar((number / divisor) + '0');
		number %= divisor;
		divisor /= 10;
	}
}
