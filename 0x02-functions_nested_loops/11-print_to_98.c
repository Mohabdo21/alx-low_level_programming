#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
	if (n < 0)
	{
	_putchar('-');
	n = -n;
	}

	if (n / 10 != 0)
	print_number(n / 10);

	_putchar((n % 10) + '0');
}

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: Starting number
 */
void print_to_98(int n)
{
	while (n != 98)
	{
	print_number(n);
	_putchar(',');
	_putchar(' ');

		if (n < 98)
		n++;
		else
		n--;
	}

	print_number(98);
	_putchar('\n');
}
