#include "main.h"
#include <stdio.h>

/**
 *_strstr - Main entry
 *@haystack: the string s
 *@needle: string accept
 *
 * Description: locates the needle in haystack
 * Return: *s or NULL
 */

char *_strstr(char *haystack, char *needle)
{
	if (!*needle)
		return (haystack);

	for (; *haystack; haystack++)
	{
		char *h = haystack;
		char *n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}
		if (!*n)
			return (haystack);
	}
	return (NULL);
}
