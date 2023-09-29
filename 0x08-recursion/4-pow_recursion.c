#include "main.h"
#include <stdio.h>

/**
*_pow_recursion - main entry
*@x: the number to be powered
*@y: the power of the number
*Return: factorial of n
*/

int _pow_recursion(int x, int y)
{
	if (y > 0)
		return (_pow_recursion((y - 1), x) * (x * x));
}
