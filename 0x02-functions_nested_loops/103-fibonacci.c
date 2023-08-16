#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int a = 1;
	unsigned long int b = 2;
	unsigned long int next;
	unsigned long int sum = 2;

    while (1)
	{
	next = a + b;

		if (next > 4000000)
		break;

	if (next % 2 == 0)
		sum += next;

	a = b;
	b = next;
	}

	printf("%lu\n", sum);

	return (0);
}
