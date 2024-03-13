#include "search_algos.h"

/**
 * move_to_end - Moves to the end of the skip list
 * @node: Pointer to the current node
 *
 * Return: Pointer to the last node in the skip list
 */
skiplist_t *move_to_end(skiplist_t *node)
{
	if (!node)
		return (NULL);

	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

/**
 * _linear_search - Performs a linear search in the skip list
 * @start: Pointer to the start node
 * @end: Pointer to the end node
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *_linear_search(skiplist_t *start, skiplist_t *end, int value)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
		start->index, end->index);

	while (start && start->n <= value)
	{
		printf("Value checked at index [%lu] = [%i]\n", start->index, start->n);
		if (start->n == value)
		{
			return (start);
		}
		start = start->next;
	}
	return (NULL);
}

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
	skiplist_t *cur_node = list, *pre_node = NULL;

	if (!cur_node)
	{
		return (NULL);
	}

	/* Use express lane to get close to the target value */
	while (cur_node->express && cur_node->n < value)
	{
		pre_node = cur_node;
		cur_node = cur_node->express;
		printf("Value checked at index [%lu] = [%i]\n",
		 cur_node->index, cur_node->n);
	}

	/* If we've reached the end of the express lane, move to the next node */
	if (!cur_node->express && cur_node->n < value)
	{
		pre_node = cur_node;
		cur_node = move_to_end(cur_node);
	}

	/* Perform linear search in the regular lane */
	return (_linear_search(pre_node, cur_node, value));
}
