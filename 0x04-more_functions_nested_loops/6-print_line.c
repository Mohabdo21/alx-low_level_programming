#include "main.h"
/**
 * print_line - function that print line on terminal with given number
 * @n: number of times of character to be printed
 */
void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{

	for (i = 0; i < n; i++)
	{
		_putchar(95);
	}
	_putchar('\n');
	}
}
