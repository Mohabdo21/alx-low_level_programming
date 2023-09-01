#include <stdio.h>
#include <stdlib.h>
/**
 * main - Prints the minimum number of coins
 * @argc: Arguments counter
 * @argv: Arguments pointer
 * Return: 0 Success, 1 Error
 */
int main(int argc, char *argv[])
{
	int change, i;
	int cents[5] = {25, 10, 5, 2, 1};
	int counter = 0;

	if (argc < 2)
	{
	printf("Error\n");
	return (1);
	}

	change = atoi(argv[1]);

	for (i = 0; i < 5; i++)
	{
		counter += change / cents[i];
		change = change % cents[i];
	}
	printf("%d\n", counter);
	return (0);
}
