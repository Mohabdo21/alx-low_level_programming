#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int print_flag;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	else if (n == 1)
	{
		_putchar('1');
		return;
	}

	/* Find the most significant bit (MSB) position */
	mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	print_flag = 0;

	while (mask > 0)
	{
		if ((n & mask) || print_flag)
		{
			if (n & mask)
				_putchar('1');
			else
				_putchar('0');
			print_flag = 1;
		}

		mask >>= 1; /* Shift the mask right by 1 bit */
	}
}
