#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and
 * sets the head to NULL.
 * @head: A pointer to a pointer to the head
 * of the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL || *head == NULL)
		return; /* Check for NULL or an empty list.*/

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}
}
