#include "main.h"
#include <stdio.h>

/**
*sqrt_helper - fct helper
*@n: the number to be squarertoot checked
*@i: the squareroot checker
*Return: squareroot of n
*/

int sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (sqrt_helper(n, i + 1));
}

/**
*_sqrt_recursion - main entry
*
*@n: the number to be squarertoot checked
*
*Return: squareroot of n
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 1));
}
