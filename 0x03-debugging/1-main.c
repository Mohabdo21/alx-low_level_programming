#include <stdio.h>
/**
* main - Entry point for the program
* Return: Always 0 (Success)
* Description: This function prints a message
* to indicate the avoidance of an infinite loop.
*/
int main(void)
{
	int i;

	printf("Infinite loop incoming :(\n");

	i = 0;
/**
* infinit loop cause:	while (i < 10)
*	{
*		putchar(i);
*	}
*/
	printf("Infinite loop avoided! \\o/\n");

	return (0);
}
