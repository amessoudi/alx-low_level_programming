#include "main.h"

/**
*_puts_recursion - main entry
*@s: the string to be printed
*/

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		return ('\n');
	}
	write(1, &s, 1);
	_puts_recursion(s + 1);
}
