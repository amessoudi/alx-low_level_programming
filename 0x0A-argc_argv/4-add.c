#include <stdlib.h>
#include "main.h"

int is_valid_number(char *str);
void print_number(int n);

/**
 * main - adds positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 if there's an invalid number
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	for (i = 1; i < argc; i++)
	{
		if (!is_valid_number(argv[i]))
		{
			_putchar('E');
			_putchar('r');
			_putchar('r');
			_putchar('o');
			_putchar('r');
			_putchar('\n');
			return (1);
		}

		sum += atoi(argv[i]);
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}

/**
 * is_valid_number - checks if a string is a valid number
 * @str: string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *str)
{
	if (!str || *str == '\0')
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}
