#include "function_pointers.h"

/**
 * print_name - function that prints a name
 * @name: the name to be printed
 * @f: pointer to function that dictates how to print the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
