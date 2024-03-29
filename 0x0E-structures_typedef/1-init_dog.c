#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: Pointer to a struct dog to be initialized
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of dog
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
