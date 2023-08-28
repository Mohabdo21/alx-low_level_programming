#include "main.h"
/**
 * print_chessboard - Prints a chessboard
 * @a: Pointer to the 2D array rep. the chessboard
 *
 * Return: Nothing
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);

			if (j != 7)
			_putchar(' ');
		}
		_putchar('\n');
	}
}
