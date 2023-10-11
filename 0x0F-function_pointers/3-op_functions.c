#include "3-calc.h"

/**
 * op_add - return the sum of a and b
 * @a: first integer
 * @b: second integer
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - return difference of a and b
 * @a: first integer
 * @b: second integer
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - return product of a and b
 * @a: first integer
 * @b: second integer
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divide a by b
 * @a: first integer
 * @b: second integer
 * Return: division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder of the division of a by b
 * @a: first integer
 * @b: second integer
 * Return: remainder of division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
