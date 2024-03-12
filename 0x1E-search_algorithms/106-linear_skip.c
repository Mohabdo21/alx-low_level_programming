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
	skiplist_t *c_node = list, *p_node = NULL;

	if (!c_node)
	{
		return (NULL);
	}

	/* Use express lane to get close to the target value */
	while (c_node->express && c_node->n < value)
	{
		p_node = c_node;
		c_node = c_node->express;
		printf("Value checked at index [%lu] = [%i]\n", c_node->index, c_node->n);
	}

	/* If we've reached the end of the express lane, move to the next node */
	if (!c_node->express && c_node->n < value)
	{
		p_node = c_node;
		while (c_node->next)
		{
			c_node = c_node->next;
		}
	}

	/* Perform linear search in the regular lane */
	printf("Value found between indexes [%lu] and [%lu]\n",
		p_node ? p_node->index : 0, c_node->index);
	while (p_node && p_node->n <= value)
	{
		printf("Value checked at index [%lu] = [%i]\n", p_node->index, p_node->n);
		if (p_node->n == value)
		{
			return (p_node);
		}
		p_node = p_node->next;
	}

	return (NULL);
}
