#include "lists.h"
/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *node = NULL;

	if (head == NULL)
	{
		exit(98);
	}

	while (current != NULL)
	{
		if (current->next >= current)
		{
			node = current;
			break;
		}
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		current = current->next;
	}

	if (node != NULL)
	{
		printf("-> [%p] %d\n", (void *)node, node->n);
		count++;
	}

	return (count);
}
