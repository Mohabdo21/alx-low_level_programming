#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *next;

	if (!list)
		return (NULL);

	next = list->express;
	prev = list;

	while (next && next->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", next->index, next->n);
		prev = next;
		if (!next->express)
		{
			while (next->next)
				next = next->next;
			break;
		}
		next = next->express;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, next->index);

	while (prev && prev->n <= next->n)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
