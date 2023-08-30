#include "main.h"
/**
 * factorial - Computes the factorial of a given number using recursion
 * @n: Input number
 *
 * Return: The factorial of n, or -1 if n is nigative
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
