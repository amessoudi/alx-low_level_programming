#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

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
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char*);
			if (!str)
				str = "(nil)";
			printf("%s", str);
			break;
		}

		if ((format[i] == 'c' || format[i] == 'i' ||
			format[i] == 'f' || format[i] == 's') && format[i + 1])
			printf(", ");

		i++;
	}
	printf("\n");
	va_end(args);
}
