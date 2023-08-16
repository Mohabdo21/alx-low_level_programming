#include <stdio.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned int n1 = 1;
	unsigned int n2 = 2;
	unsigned int next;	
	int count;

	printf("%d, %d", n1, n2);


	for (count = 2; count < 98; count++)
	{
	next = n1 + n2;

	printf(", %d", next);


	n1 = n2;
	n2 = next;
	}

	printf("\n");

	return (0);
}
