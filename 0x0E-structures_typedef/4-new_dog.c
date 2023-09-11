#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - Creates a new dog and copies the name, owner and age
 * @name: Dog's name
 * @age: Dog's Age
 * @owner: Dog's Owner
 *
 * Return: Pointer to the newly created dog_t, else NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int name_len, owner_len;
	int i;

	name_len = 0;
	owner_len = 0;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[name_len] != '\0')
		name_len++;
	while (owner[owner_len] != '\0')
		owner_len++;

	dog_t *new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
		return (NULL);

	new_dog->name = malloc(name_len + 1);

	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = malloc(owner_len + 1);

	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	for (i = 0; i <= name_len; i++)
		new_dog->name[i] = name[i];
	for (i = 0; i <= owner_len; i++)
		new_dog->owner[i] = owner[i];

	new_dog->age = age;

	return (new_dog);
}
