#include "main.h"
/**
 * print_number - Function to print an integer
 * @n: The Number Should Printed
 */
void print_number(int n)
{
	unsigned int divsr = n;

	if (n < 0)
	{
		n *= -1;
		divsr = n;
		_putchar(45);
	}
	divsr /= 10;
	if (divsr != 0)
	{
		print_number(divsr);
	}
		_putchar((unsigned int) n % 10 + 48);
}
