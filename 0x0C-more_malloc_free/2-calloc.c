#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _calloc - Allocates memory for an array, initializes to zero
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 *
 * Return: A pointer to the allocated memory,
 * if nmemb or size is 0, or if malloc fails return NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size, i;
	char *char_ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);

	if (ptr == NULL)
		return (NULL);

	char_ptr = (char *)ptr;
	for (i = 0; i < total_size; i++)
		char_ptr[i] = 0;

	return (ptr);
}
