#include "main.h"
/**
 * _pow_recursion - Computes the value of the first
 *	number powered to sec number
 *
 * @x: Number
 * @y: Power
 * Return: Value of the first number raised to second number
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	return (x * _pow_recursion(x, (y - 1)));
}
