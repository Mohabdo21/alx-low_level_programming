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
	const listint_t *loop_node = NULL;

	if (head == NULL)
		exit(98);

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		if (current->next >= current)
		{
			loop_node = current;
			break;
		}

		current = current->next;
	}

	if (loop_node != NULL)
	{
		printf("-> [%p] %d\n", (void *)loop_node, loop_node->n);
		count++;
	}

	return (count);
}
