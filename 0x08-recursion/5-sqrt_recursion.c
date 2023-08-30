#include "main.h"
/**
 * _sqrt_recursion - Cumputes the Square root of Number
 * @n: Given Number
 *
 * Return: Square root if number is natural, else return -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 1));
}

/**
 * sqrt_helper - Helper function to find the square root recursively
 * @n: Number to find square roor for
 * @guess: The current guess
 *
 * Return: The square root of n if found, else -1
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}
