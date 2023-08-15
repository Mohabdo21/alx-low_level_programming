#include <stdio.h>
#include "main.h"
/**
 * main - The Entry point of the program
 *
 * Return: 0 Always (Success)
 */
int main(void)
{
	int limit = 1024;
	int sum = calculate_multiples_sum(limit);

	printf("%d\n", sum);

	return (0);
}
