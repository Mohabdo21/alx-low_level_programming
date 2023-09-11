#include <stdio.h>
#include "dog.h"
/**
 * init_dog - initiate a variable type struct dog
 * @d: New dog
 * @name: Dog name
 * @age: Dog age
 * @owner: Dog Owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
