#include "lists.h"
/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * This function can print lists with a loop.
 * It goes through the list only once.
 * If the function fails, it exits the program with status 98.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t node_count = 0;
	const listint_t *current = head;
	const listint_t *runner = head;

	if (head == NULL)
		exit(98);

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		node_count++;

		runner = head;
		while (runner != current)
		{
			if (runner->next == current->next)
			{
				printf("-> [%p] %d\n", (void *)current->next, current->next->n);
				return (node_count);
			}
			runner = runner->next;
		}
		current = current->next;
	}

	return (node_count);
}
