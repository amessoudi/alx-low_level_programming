#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
*sum_them_all - prints the sum of all ints
*@n: the numbers to be summed
*
*Return: the sum of all n's
*/

int sum_them_all(const unsigned int n, ...)
{
	va_list argmnts;
	int sum = 0;

	if (n == 0)
	{
		return (0);
	}

	va_start(argmnts, n);

	for (unsigned int i = 0; i < n; i++)
	{
		sum += va_arg(argmnts, int);
	}

	va_end(argmnts);

	return (sum);
}
