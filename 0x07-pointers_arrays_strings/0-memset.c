#include "main.h"

/**
 * memeset - entry point
 *
 *Description: definition of memeset function
 *Return : Always S (success)
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
