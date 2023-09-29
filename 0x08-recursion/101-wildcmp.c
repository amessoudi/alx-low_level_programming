#include <stdio.h>

/**
 * wildcmp - compares two strings and returns 1 if the strings
 * can be considered identical, otherwise returns 0.
 * @s1: First string.
 * @s2: Second string, can possibly contain the special character '*'.
 * Return: 1 if strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' && *s2 == '*')
		return (wildcmp(s1, s2 + 1));
	if (*s1 == '\0' || *s2 == '\0')
		return (0);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	return (0);
}
