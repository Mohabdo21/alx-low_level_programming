#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory
 * @old_size: Size of the old memory block in bytes
 * @new_size: New size of the memory block in bytes
 *
 * Return: Pointer to the reallocated memory block
 * If new_size == old_size, return ptr
 * If new_size is zero and ptr is not NULL,
 * free(ptr) and return NULL
 * If malloc fails, return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		new_size = old_size;

	for (i = 0; i < new_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
