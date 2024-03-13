#include <stdio.h>
#include "search_algos.h"

/**
 * print_list_e - Prints the value checked at a given index
 * @list: The list to be printed
 */
void print_list_e(const listint_t *list)
{
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
}

/**
 * jump_list - Searches for a value in a sorted list of integers using the
 * jump search algorithm
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: A pointer to the first node where value is located,
 * or NULL if value is not present
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump;
	listint_t *prev, *next;
	size_t i;

	if (!list || size == 0)
		return (NULL);

	jump = sqrt(size);
	prev = list;
	next = list;

	/* Jump through the list */
	while (next->index < size - 1 && next->n < value)
	{
		prev = next;

		for (i = 0; i < jump && next->next; i++)
			next = next->next;

		print_list_e(next);
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, next->index);

	/* Perform linear search in the range */
	while (prev && prev->index <= next->index)
	{
		print_list_e(prev);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
