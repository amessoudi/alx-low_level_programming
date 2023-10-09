#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings up to n bytes from s2
 * @s1: first string
 * @s2: second string
 * @n: bytes of s2 to include
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i = 0, j = 0;
	char *result;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	while (s1[len1])
		len1++;

	while (s2[len2])
		len2++;

	if (n >= len2)
		n = len2;

	/* Allocate memory for the new string */
	result = malloc(len1 + n + 1);
	if (result == NULL)
		return (NULL);

	/* Copy s1 into the new string */
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}

	/* Copy up to n bytes of s2 into the new string */
	while (j < n)
	{
		result[i] = s2[j];
		i++;
		j++;
	}

	result[i] = '\0';

	return (result);
}
