#include "main.h"
/**
 * is_prime_number - Check if the input number is a Prime number
 * @n: Number to check
 *
 * Return: 1 if the input Number is Prime, else 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - helper function to  check
 * @n: The number to be checked
 * @divisor: Current divisor to check divisability
 *
 * Return: 1 if Number Prime, else 0
 */
int is_prime_helper(int n, int divisor)
{
	if (divisor >= n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_prime_helper(n, divisor + 1));
}
