#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98.
 * @n: The starting number.
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		int num;

		if (n < 0)
		{
			_putchar('-');
			num = -n;
		}
		else
		{
			num = n;
		}

		if (num >= 100)
			_putchar((num / 100) + '0');
		if (num >= 10)
			_putchar(((num / 10) % 10) + '0');
		_putchar((num % 10) + '0');

		if (n != 98)
		{
			_putchar(',');
			_putchar(' ');
		}

		if (n > 98)
			n--;
		else
			n++;
	}
	_putchar('\n');
}
