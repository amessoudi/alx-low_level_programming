#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - prints numbers followed by a new line.
 * @separator: string to be printed between numbers
 * @n: the number of integers passed to the function
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		
		if (num < 0)
		{
			_putchar('-');
			num = -num;
		}

		
		if (num / 10 == 0) 
			_putchar(num + '0');
		else 
		{
			int divisor = 1;

			while (num / divisor > 9)
				divisor *= 10;

			while (divisor)
			{
				_putchar((num / divisor) % 10 + '0');
				divisor /= 10;
			}
		}

		
		if (separator != NULL && i < n - 1)
		{
			const char *sep = separator;
			while (*sep)
			{
				_putchar(*sep++);
			}
		}
	}

	_putchar('\n');
	va_end(args);
}
