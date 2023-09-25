#include "main.h"

/**
 *_memset - entry point
 *@s: the starting point
 *@b: the constant byte
 *@n: the number of boxes affected in memory
 *
 *Description: definition of memeset functio
 *
 *Return: Always S (success)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
