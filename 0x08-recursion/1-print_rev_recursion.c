#include "main.h"
#include <stdio.h>

/**
*_print_rev_recursion - main entry
*@s: the string to be printed
*/

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		putchar('\n');
		return;
	}
	_print_rev_recursion(++s);
	putchar(*s);
}
