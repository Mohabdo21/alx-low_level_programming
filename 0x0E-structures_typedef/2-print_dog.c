#include <stdio.h>
#include "dog.h"
/**
 * print_dog - Function that prints a struct dog
 * @d: struct subname
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");

	if (d->age == NULL)
	{
		printf("(nil)\n");
	}
	else
	{
	printf("Age: %f\n", d->age);
	}

	printf("Owner: %s\n", (d->owner != NULL) ? d->name : "(nil)");
}
