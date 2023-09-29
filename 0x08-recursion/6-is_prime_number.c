#include "main.h"
#include <stdio.h>

/**
*is_prime_helper - fct helper
*@n: the number to be prime checked
*@i: the prime checker
*Return: squareroot of n
*/
int is_prime_helper(int n, int i)
{

	if (i * i > n)
		return (1);


	if (n % i == 0)
		return (0);

	return (is_prime_helper(n, i + 1));
}

/**
*is_prime_number - fct
*@n: the number to be prime checked
*
*Return: prime or not
*/
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	return (is_prime_helper(n, 2));
}
