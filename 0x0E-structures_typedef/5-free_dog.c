#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - Function that frees Memory allocated for struct dog
 * @d: A pointer to dog register
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
