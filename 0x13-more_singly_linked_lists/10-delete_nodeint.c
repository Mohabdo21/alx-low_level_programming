#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of
 * a listint_t linked list.
 * @head: A pointer to a pointer to the head of
 * the listint_t list.
 * @index: The index of the node to delete, starting at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	previous = NULL;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}
