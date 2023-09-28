#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int num;
	char *endianness_check;

	num = 1;
	endianness_check = (char *)&num;

	/* If the least significant byte is 1, it's little endian. */
	if (*endianness_check == 1)
		return (1);
	else
		return (0);
}
