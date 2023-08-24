#include "main.h"
/**
 * infinite_add - Adds two numbers rep. as strings
 * @n1: First number string
 * @n2: Second number string
 * @r: Buffer to store result
 * @size_r: The size of the buffer
 *
 * Return: Pointer to the result (r), or 0 if it's larger than provided buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len_n1 = 0;
	int len_n2 = 0;
	int max_len = 0;
	int carry = 0;
	int i, sum, digit;

	while (n1[len_n1] != '\0')
		len_n1++;
	while (n2[len_n2] != '\0')
		len_n2++;
	max_len = (len_n1 > len_n2) ? len_n1 : len_n2;
	if (max_len + 1 > size_r)
		return (0);
	r[max_len + 1] = '\0';
	for (i = max_len; i > 0; i--)
	{
		len_n1--;
		len_n2--;
		sum = carry;
		if (len_n1 >= 0)
			sum += n1[len_n1] - '0';
		if (len_n2 >= 0)
			sum += n2[len_n2] - '0';
		digit = sum % 10;
		carry = sum / 10;
		r[i] = digit + '0';
	}
	if (carry)
	{
		if (max_len + 2 > size_r)
			return (0);
		r[0] = carry + '0';
		return (r);
	}
	return (&r[1]);
}
