#include "main.h"

/**
 * _islower - Checks for a lowercase character.
 * @c: The character to be checked.
 *
 * Return: 1 if c is lowercase, 0 otherwise.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1); /* c is a lowercase letter */
	else
		return (0); /* c is not a lowercase letter */
}
