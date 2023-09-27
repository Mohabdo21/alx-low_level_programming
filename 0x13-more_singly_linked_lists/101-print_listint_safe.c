#include "lists.h"
/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	const listint_t *current = head;
	const listint_t *address_list[10000];

	while (current != NULL)
	{
		size_t i;

		for (i = 0; i < node_count; i++)
		{
			if (current == address_list[i])
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (node_count);
			}
		}

		address_list[node_count] = current;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		node_count++;

		if (node_count >= 10000)
		{
			fprintf(stderr, "Error: List is too long\n");
			exit(98);
		}
	}

	return (node_count);
}
