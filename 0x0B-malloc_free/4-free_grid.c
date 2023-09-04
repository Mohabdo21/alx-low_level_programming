#include "main.h"
#include <stdlib.h>
/**
 * free_grid - free a 2D grid
 * @grid: 2D integer array
 * @height: 2D array height
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
