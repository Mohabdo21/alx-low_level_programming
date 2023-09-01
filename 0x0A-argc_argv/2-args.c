#include <stdio.h>
/**
 * main - prints all arguments it recieved
 * @argc: arguments counter
 * @argv: arguments string pointer
 *
 * Return: 0 Always success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
