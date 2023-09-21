#include "lists.h"

/**
 * list_len - returns the number of elements in a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of elements (nodes) in the list
 */
size_t list_len(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}
