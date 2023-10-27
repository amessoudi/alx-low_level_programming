#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Description: This function converts a string of binary
 * characters to an unsigned int value. If the string
 * contains characters that are not 0 or 1, or if b is NULL,
 * the function will return 0.
 *
 * Return: the converted number, or 0 if there is an error.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	while (*b)
	{
		if (*b == '1')
		{
			num = (num << 1) | 1;
		}
		else if (*b == '0')
		{
			num <<= 1;
		} else
		{

			return (0);
		}
		b++;
	}
	return (num);
}
