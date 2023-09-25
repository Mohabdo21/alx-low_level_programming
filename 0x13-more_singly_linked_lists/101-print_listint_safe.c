#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely using
 * Floyd's Tortoise and Hare algorithm.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *slow_ptr, *fast_ptr;

	if (head == NULL)
		exit(98);

	slow_ptr = head;
	fast_ptr = head;

	while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		nodes++;
		slow_ptr = slow_ptr->next;
		fast_ptr  = fast_ptr->next->next;

		if (slow_ptr == fast_ptr)
		{
			printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
			return (nodes);
		}
	}

	return (nodes);
}
