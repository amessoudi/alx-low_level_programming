#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_numbers - Prints numbers followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 *
 * Return: void.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int number;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		number = va_arg(args, int);
		
		if (number < 0)
		{
			_putchar('-');
			number = -number;
		}
		
		
		if (number == 0)
			_putchar('0');
		else
		{
			int divisor = 1;
			
			while (number / divisor > 9)
				divisor *= 10;
			
			while (divisor)
			{
				_putchar((number / divisor) % 10 + '0');
				divisor /= 10;
			}
		}

		
		if (separator && i < n - 1)
		{
			const char *sep_ptr = separator;
			while (*sep_ptr)
				_putchar(*sep_ptr++);
		}
	}

	_putchar('\n');
	va_end(args);
}
