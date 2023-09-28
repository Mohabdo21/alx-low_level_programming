#include "main.h"

/**
 * flip_bits - Returns the number of bits to flip to get from n to m.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	unsigned int count;

	diff = n ^ m;
	count = 0;

	while (diff > 0)
	{
		count += diff & 1;
		diff >>= 1; /* Shift right to check the next bit */
	}

	return (count);
}
