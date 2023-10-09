#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @str: input string
 * Return: number of words
 */
int word_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: input string
 * Return: array of words
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, wc, word_start;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = word_count(str);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, k = 0; i < wc; i++)
	{
		while (str[k] == ' ')
			k++;
		word_start = k;
		while (str[k] != ' ' && str[k] != '\0')
			k++;
		len = k - word_start;

		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			words[i][j] = str[word_start + j];
		words[i][j] = '\0';
	}
	words[wc] = NULL;
	return (words);
}
