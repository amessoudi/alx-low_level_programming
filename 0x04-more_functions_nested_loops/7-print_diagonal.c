#include "main.h"

/**
* print_diagonal - Prints diagonaly.
*@n: the numbers of rows
*
 */

void print_diagonal(int n)
{
    int i, j;
	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < n; i++)
	{
		/* Print spaces for indentation */
		for (j = 0; j < i; j++)
		{
			_putchar(' ');
		}
		_putchar('\\');
		_putchar('\n');
}
