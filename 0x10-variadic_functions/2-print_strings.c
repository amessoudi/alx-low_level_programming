#include "variadic_functions.h"
#include <stdarg.h>

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

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char*);

		if (str == NULL)
			for (char *s = "(nil)"; *s; s++)
				_putchar(*s);
		else
			for (int j = 0; str[j]; j++)
				_putchar(str[j]);

		// If separator is not NULL and it's not the last string, print separator
		if (separator && i < n - 1)
			for (int j = 0; separator[j]; j++)
				_putchar(separator[j]);
	}

	_putchar('\n');
	va_end(args);
}
