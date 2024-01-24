#!/usr/bin/python3
"""
5-island_perimeter module
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    width = len(grid[0])
    height = len(grid)
    grid_expanded = [[0] * (width + 2)]
    for row in grid:
        grid_expanded.append([0] + row + [0])
    grid_expanded.append([0] * (width + 2))

    perimeter = 0

    for i in range(1, height + 1):
        for j in range(1, width + 1):
            if grid_expanded[i][j] == 1:
                perimeter += grid_expanded[i - 1][j] == 0  # up
                perimeter += grid_expanded[i + 1][j] == 0  # down
                perimeter += grid_expanded[i][j - 1] == 0  # left
                perimeter += grid_expanded[i][j + 1] == 0  # right

    return perimeter
