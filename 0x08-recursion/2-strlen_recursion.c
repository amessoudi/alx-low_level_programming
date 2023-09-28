#include "main.h"
#include <stdio.h>

/**
*_strlen_recursion - main entry
*@s: the string to be printed
*Return: length of the string
*/

int _strlen_recursion(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen_recursion(s + 1));
	}
	else
	{
		return (0);
	}
}
