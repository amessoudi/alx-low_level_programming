#include "main.h"
#include <stdio.h>

/**
*factorial - main entry
*@n: the number to be factorialized
*Return: factorial of n
*/

int factorial(int n)
{
	if (n > 0)
	{
		n = (n * factorial(n - 1));
		return (n);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}
