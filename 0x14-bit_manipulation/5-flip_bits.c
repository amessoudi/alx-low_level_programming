#include "main.h"

/**
 * flip_bits - counts the number of bits needed to be flipped
 *             to convert a number to another
 * @n: the first number
 * @m: the second number
 * Return: the number of bits needed to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, bits = 0;

	while (xor)
	{
		bits += xor & 1;
		xor >>= 1;
	}

	return (bits);
}
