#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * print_all - prints anything.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			putchar(va_arg(args, int));
			break;
		case 'i':
			print_int(va_arg(args, int));
			break;
		case 'f':
			break;
		case 's':
			str = va_arg(args, char*);
			if (!str)
				str = "(nil)";
			print_str(str);
			break;
		}

		if ((format[i] == 'c' || format[i] == 'i' ||
			format[i] == 'f' || format[i] == 's') && format[i + 1])
		{
			putchar(',');
			putchar(' ');
		}

		i++;
	}
	putchar('\n');
	va_end(args);
}

/**
 * print_int - prints an integer.
 * @n: The integer.
 *
 * Return: void.
 */
void print_int(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		print_int(n / 10);
	putchar(n % 10 + '0');
}

/**
 * print_str - prints a string.
 * @s: The string.
 *
 * Return: void.
 */
void print_str(char *s)
{
	while (*s)
		putchar(*s++);
}
