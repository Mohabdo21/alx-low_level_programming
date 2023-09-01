#include <stdio.h>
/**
 * main - Prints the number of arguments
 * @argc: number of arguments
 * @argv: a pointer to arguments string
 * Return: 0 Always success
 */
int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}
