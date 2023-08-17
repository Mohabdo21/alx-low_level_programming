#include "main.h"
/**
 * print_number - Function to print an integer
 * @n: The Number Should Printed
 */
void print_number(int n)
{
	int divsr = 1;
	int tmp = n;

	if (n < 0)
	{
		_putchar(45);
		n *= -1;
	}

	while (tmp > 9)
	{
		divsr *= 10;
		tmp /= 10;
	}

	while (divsr != 0)
	{
		_putchar((n / divsr) + '0');
		n %= divsr;
		divsr /= 10;
	}
}
