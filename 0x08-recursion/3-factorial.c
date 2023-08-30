#include "main.h"
/*
 * factorial - Computes the factorial of a given number
 * @n: Input number
 *
 * Return: The factorial of the given number
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}
