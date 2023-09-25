#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the
 * end of a listint_t list.
 * @head: A pointer to a pointer to the head
 * of the listint_t list.
 * @n: The integer value to be stored in the new node.
 *
 * Return: The address of the new element, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *current;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
	/* If the list is empty, make the new node the head.*/
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		/* Add the new node at the end of the list.*/
		current->next = new_node;
	}

	return (new_node);
}
