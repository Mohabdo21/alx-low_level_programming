#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - Adds two numbers
 * @argc: Arguments counter
 * @argv: Arguments pointer
 * Return: 0 Success, 1 Error
 */
int main(int argc, char *argv[])
{
	int i,j,sum;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
