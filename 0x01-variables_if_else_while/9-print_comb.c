#include <stdio.h>

/**
 * main - The Entry point of the program
 *
 * Return: 0 Always (Success)
 */
int main(void)
{

	int i;

	for (i = 0; i < 10; i++){
		putchar(i + '0');

	if (i < 9){
		putchar(',');
		putchar(' ');
	}
}
putchar('\n');
return (0);
}
