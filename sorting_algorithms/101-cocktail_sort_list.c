#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Update the next pointer of the first node */
	node1->next = node2->next;

	/* Update the previous pointer of the next node if it exists */
	if (node2->next != NULL)
		node2->next->prev = node1;

	/* Update the previous pointer of the second node */
	node2->prev = node1->prev;

	/**
	 * Update the next pointer of the previous node if it exists,
	 * otherwise update the head of the list
	 */
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	/**
	 * Update the next pointer of the second node and the
	 * previous pointer of the first node
	 */
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 *
 * The function uses a while loop to continue
 * sorting as long as swaps are being made. It first iterates from the start
 * to the end of the list, swapping nodes as necessary, and then from the end
 * to the start. If no swaps are made during a pass, the list is sorted and
 * the function returns.
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	while (swapped)
	{
		swapped = false;
		/* Iterate from the start to the end of the list */
		while (node->next != NULL)
		{
			/* Swap nodes if the current node is greater than the next node */
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				print_list(*list), swapped = true;
			}
			else
				node = node->next;
		}
		if (!swapped)
			break;

		swapped = false;
		/* Iterate from the end to the start of the list */
		while (node->prev != NULL)
		{
			/* Swap nodes if the previous node is greater than the current node */
			if (node->prev->n > node->n)
			{
				swap_nodes(list, node->prev, node);
				print_list(*list), swapped = true;
			}
			else
				node = node->prev;
		}
	}
}
