#include "main.h"
#include <stdlib.h>

/**
 * print_to_98 - Prints natural numbers from n to 98, followed by a new line.
 * @n: The starting number.
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
		_putchar(',');
		_putchar(' ');

		if (n > 98)
			n--;
		else
			n++;
	}
	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
