#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string is a digit
 * @s: string to check
 * Return: 0 if false, 1 if true
 */
int is_digit(char *s)
{
	int result = 1;

	while (*s)
	{
		if (*s < '0' || *s > '9')
		{
			result = 0;
			break;
		}
		s++;
	}
	return (result);
}

/**
 * print_string - prints a string using _putchar
 * @str: string to print
 */
void print_string(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

/**
 * mul - multiplies two numbers
 * @num1: first number
 * @num2: second number
 * Return: result
 */
char *mul(char *num1, char *num2)
{
	return (NULL);
}

/**
 * main - multiplies two positive numbers and prints the result.
 * @argc: argument count
 * @argv: argument vectors
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_string("Error\n");
		exit(98);
	}

	result = mul(argv[1], argv[2]);
	if (result == NULL)
	{
		print_string("Error\n");
		exit(98);
	}

	print_string(result);
	_putchar('\n');
	free(result);
	return (0);
}
