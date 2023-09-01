#include <stdio.h>
/**
 * main - Entry point, function to print file name
 * @argc: count of the arguments supplied
 * @argv: an array of pointers to the strings
 *Return: 0 Always success
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
