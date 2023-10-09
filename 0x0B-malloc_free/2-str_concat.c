#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer to the concatenated string or NULL if failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of the strings */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* Allocate memory for the concatenated string, +1 for the null byte */
	concat = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	/* Copy the contents of s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy the contents of s2 */
	for (j = 0; j < len2; j++, i++)
		concat[i] = s2[j];
	concat[i] = '\0';

	return (concat);
}
