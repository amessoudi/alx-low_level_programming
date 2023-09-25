#include "main.h"
#include <stdio.h>

/**
 *_strpbrk - Main entry
 *@s: the string s
 *@accept: string accept
 *
 * Description: locates the first occurence of string s in accept
 * Return: *s
 */

char *_strpbrk(char *s, char *accept)
{
	char a;

	for (; *s; s++)
	{
		for (a = accept, *a; a++)
		{
			if (*s == *a)
				return (s);
		}
	}
	return (NULL);
}
