#include "lists.h"
/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	long int variance;

	if (head == NULL)
	{
		exit(98);
	}

	while (head)
	{
		variance = head - head->next;
		nodes++;

		printf("[%p] %d\n", (void *)head, head->n);

		if (variance > 0)
			head = head->next;
		else
		{
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
			break;
		}
	}

	return (nodes);
}
