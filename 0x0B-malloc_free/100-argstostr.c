#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: argument count
 * @av: argument vector (array of strings)
 * Return: pointer to the new string or NULL if failure
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len = 0, pos = 0;

	/* Base cases */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate the total length for the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* For the \n */
	}

	/* Allocate memory for the concatenated string */
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Populate the new string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, pos++)
			str[pos] = av[i][j];
		str[pos] = '\n';
		pos++;
	}
	str[pos] = '\0';

	return (str);
}
