#include "main.h"
#include <stdlib.h>
/**
 * *_strchr - Main entry
 *@*s: pointer to the string s
 *@c: the char we're looking for
 *
 *Description: REturns a pointer to the first occ of char
 *Return: Char c if success NULL if Not
 */

char *_strchr(char *s, char c)
{
	while (*s || c == '\0')
	{
		if (*s == c)
		{
			return s;
		}
		if (*s == '\0')
			break;
		s++;
	}
	return NULL;
}
