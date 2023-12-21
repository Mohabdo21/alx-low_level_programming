#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list.
 * Description: of integers in ascending order
 * @list: doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *next;


	/* bail out when only one item */
	if (!list || !*list || !(*list)->next)
		return;

	next = *list;

	while ((next = next->next))
	{
		while ((prev = next->prev) && prev->n > next->n)
		{
			prev->next = next->next;
			if (prev->prev)
				prev->prev->next = next;
			next->prev = prev->prev;
			prev->prev = next;
			if (next->next)
				next->next->prev = prev;
			next->next = prev;

			/* set head only when swapping 1st node(i.e head!) */
			*list = !next->prev ? next : *list;
			print_list(*list);
		}
	}
}
