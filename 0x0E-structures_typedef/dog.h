#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Information about a dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 * Description: Data structure to store information about a dog
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} Dog;

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */
