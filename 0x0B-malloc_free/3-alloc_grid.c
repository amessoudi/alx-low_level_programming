#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: width of the 2D array
 * @height: height of the 2D array
 * Return: pointer to the 2D array or NULL if failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	/* Check for invalid dimensions */
	if (width <= 0 || height <= 0)
		return (NULL);

	/* Allocate memory for the rows (height) */
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	/* Allocate memory for each column (width) and initialize to 0 */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			/* If allocation fails, free the previously allocated memory */
			for (j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
