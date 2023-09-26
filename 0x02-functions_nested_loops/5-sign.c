#include "main.h"

/**
 * print_sign - Prints the sign of a number.
 * @n: The number to be checked.
 *
 * Return: 1 and prints + if n is greater than zero,
 * 0 and prints 0 if n is zero,
 * -1 and prints - if n is less than zero.
 */
int print_sign(int n)
{
	if (n > 0) /* n is positive */
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0) /* n is zero */
	{
		_putchar('0');
		return (0);
	}
	else /* n is negative */
	{
		_putchar('-');
		return (-1);
	}
}
