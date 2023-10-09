#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void print_number(int n);

/**
 * main - multiplies two numbers and prints the result
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 1 if program does not receive two arguments
 */
int main(int argc, char *argv[])
{
	int num1, num2, product;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	product = num1 * num2;

	print_number(product);
	_putchar('\n');

	return (0);
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
