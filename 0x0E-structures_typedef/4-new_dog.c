#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to duplicated string or NULL if it fails.
 */
char *_strdup(char *str)
{
	char *duplicate;
	int i, len = 0;

	if (!str)
		return (NULL);

	while (str[len])
		len++;

	duplicate = malloc(len + 1);
	if (!duplicate)
		return (NULL);

	for (i = 0; i < len; i++)
		duplicate[i] = str[i];

	duplicate[len] = '\0';

	return (duplicate);
}

/**
 * new_dog - Creates a new dog with given parameters.
 * @name: Dog's name.
 * @age: Dog's age.
 * @owner: Dog's owner.
 *
 * Return: Pointer to new dog_t.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;

	newDog = malloc(sizeof(dog_t));
	if (!newDog)
		return (NULL);

	newDog->name = _strdup(name);
	if (!newDog->name)
	{
		free(newDog);
		return (NULL);
	}

	newDog->owner = _strdup(owner);
	if (!newDog->owner)
	{
		free(newDog->name);
		free(newDog);
		return (NULL);
	}
	newDog->age = age;

	return (newDog);
}
