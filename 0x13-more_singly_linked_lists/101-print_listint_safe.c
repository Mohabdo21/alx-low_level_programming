#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	const listint_t *loop_start = NULL;
	size_t node_count = 0;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		node_count++;

	if (current->next >= current)
	{
		loop_start = current->next;
		printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
		break;
	}

	current = current->next;
	}

	if (loop_start != NULL)
	{
		current = head;
		while (current != loop_start)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			node_count++;
			current = current->next;
		}
	}

	return (node_count);
}
