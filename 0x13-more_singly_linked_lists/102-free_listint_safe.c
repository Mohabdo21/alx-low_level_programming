#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to a pointer to the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0;
	listint_t *current, *temp;
	listint_t *address_list[10000];

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size_t i;

		for (i = 0; i < node_count; i++)
		{
			if (current == address_list[i])
			{
				*h = NULL;
				return (node_count);
			}
		}

		address_list[node_count] = current;
		temp = current->next;
		free(current);
		current = temp;
		node_count++;

		if (node_count >= 10000)
		{
			return (node_count);
		}
	}

	*h = NULL;
	return (node_count);
}
