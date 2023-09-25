#include "main.h"
#include <stdio.h>

/**
 *print_chessboard - Main entry
 *@a: the chessboard length
 *
 * Description: prints the chessboard
 * Return: Void
 */

void print_chessboard(char (*a)[8])
{
	int i;
	int j;

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
