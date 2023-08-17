#include <stdio.h>
/**
 * main - The Entry point of the Program
 * Program find and print the largest prime factorof the number 612852475143
 * Return: 0 Always (Success)
 */
int main(void)
{
	unsigned long num = 612852475143;
	unsigned long l_prime = 2;

	while (num > 1)
	{
		if (num % l_prime == 0)
		{
			num /= l_prime;
		}
		else
		{
			l_prime++;
		}
	}

	printf("%lu\n", l_prime);

	return (0);
}
