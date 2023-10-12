#ifndef VARDIADIC_FUNCTION_H
#define VARDIADIC_FUNCTION_H

#include <stdarg.h>

int sum_them_all(const unsigned int n, ...);
void _putchar(char c);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);

#endif
