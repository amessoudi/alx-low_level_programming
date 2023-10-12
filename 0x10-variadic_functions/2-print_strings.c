#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_strings - Prints strings followed by a new line.
 * @separator: The string to be printed between the strings.
 * @n: The number of strings passed to the function.
 *
 * Return: void.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;
	char *s;
	int j;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char*);

		if (str == NULL)
		{
			s = "(nil)";
			while (*s)
				_putchar(*s++);
		}
		else
		{
			for (j = 0; str[j]; j++)
				_putchar(str[j]);
		}

		if (separator && i < n - 1)
		{
			for (j = 0; separator[j]; j++)
				_putchar(separator[j]);
		}
	}

	_putchar('\n');
	va_end(args);
}
