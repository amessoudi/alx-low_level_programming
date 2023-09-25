#include "main.h"
#include <stdio>

/**
 * _strspn - Main entry
 *@s: number of bytes of initial segment
 *@accept: the string to be analyzed
 *
 * Description: Returns the number of bytes
 * Return: s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	for (; *s; s++)
	{
		int p = 0;

		for (char *a = accept; *a; a++)
		{
			if (*s == *a)
			{
				p = 1;
				break;
			}
		}
		if (p)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return (count);
}
