#include <stdio.h>
/**
 * main - Entry point of thr program
 * prints the numbers from 1 to 100, followed by a new line
 * Print "Fizz" instead of 3 multiples, & "Buzz" instead of 5 multipules
 * FizzBuzz instead of 3, 5 multiples
 * Return: 0 Always (Success)
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
	if (i % 3 == 0 && i % 5 == 0)
	{
		printf("FizzBuzz");
	}
	else if (i % 3 == 0)
	{
		printf("Fizz");
	}
	else if (i % 5 == 0)
	{
		printf("Buzz");
	}
	else
	{
	printf("%d", i);
	}
	if (i != 100)
	{
		printf(" ");
	}
	}
	printf("\n");
	return (0);
}
