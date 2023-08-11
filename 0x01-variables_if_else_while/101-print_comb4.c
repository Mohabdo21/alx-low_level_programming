#include <stdio.h>

/**
 * main - The Entry point of the program
 *
 * Return: 0 Always (Success)
 */
int main(void)
{
	int i, j, k;

	for (i = 0; i <= 7 ; i++)
	{
		for (j = i + 1; j <= 8 ; j++)
		{
			for (k = j + 1; k <= 9 ; k++)
			{
				putchar(i + '0');
				putchar(j + '0');
				putchar(k + '0');

				if (i < 7)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
putchar('\n');
return (0);
}
