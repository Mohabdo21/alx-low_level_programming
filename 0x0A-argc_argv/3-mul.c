#include <stdio.h>
#include <stdlib.h>
/**
 * main - Multiplies two numbers
 * @argc: arguments counter
 * @argv: arguments pointer
 * Return: 0 Success, 1 Error
 */
int main(int argc, char *argv[])
{
	int result;

	while (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	result = atoi(argv[1]) * atoi(argv[2]);

	printf("%d\n", result);

	return (0);
}
