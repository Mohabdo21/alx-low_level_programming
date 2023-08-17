#include "main.h"
/**
 * print_triangle - Prints triangle using _putchar(#)
 * @size: is the size of the triangle
 */
void print_triangle(int size)
{
	int i;
	int j;
	int k;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= size; i++)
		{
			for (j = 1; j <= size - i; j++)
			{
			_putchar(' ');
			}
			for (k = 1; k <= i; k++)
			{
			_putchar('#');
			}
		_putchar('\n');
		}
	}
}
