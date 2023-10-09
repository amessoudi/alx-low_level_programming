#include "main.h"
#include <stdlib.h>

/**
 * print_number - Prints an integer as a string.
 * @n: The integer.
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - Calculates the minimum number of coins to make change.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 *
 * Return: 0 if successful, otherwise returns 1.
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	if (argc != 2)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	coins += cents / 25;
	cents %= 25;

	coins += cents / 10;
	cents %= 10;

	coins += cents / 5;
	cents %= 5;

	coins += cents;

	print_number(coins);
	_putchar('\n');

	return (0);
}

