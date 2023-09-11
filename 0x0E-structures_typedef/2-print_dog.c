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

	while (d->age != NULL)
	{
		printf("Age: %f\n", d->age);
	}
	else
	{
	printf("Age: (nil)\n");
	}

	printf("Owner: %s\n", (d->owner != NULL) ? d->name : "(nil)");
}
