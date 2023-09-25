#include "lists.h"

/**
 * detect_loop - Detects a loop in a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the start of the loop, or NULL if no loop is detected
 */
const listint_t *detect_loop(const listint_t *head)
{
	const listint_t *slow_ptr = head;
	const listint_t *fast_ptr = head;

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		if (!(fast_ptr->next->next))
			break;
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = slow_ptr->next;
			return (slow_ptr);
		}
	}
	return (NULL);
}

/**
 * print_list - Prints a linked list
 * @head: Pointer to the head of the list
 * @loop_start: Pointer to the start of a loop in the list, or NULL if no loop
 *
 * Return: Number of nodes printed
 */

size_t print_list(const listint_t *head, const listint_t *loop_start)
{
	size_t counter = 0;

	while (head)
	{
		counter++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (head == loop_start)
		{
			printf("-> [%p] %d\n", (void *)head, head->next->n);
			exit(98);
		}
		head = head->next;
	}
	return (counter);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely using
 * Floyd's Cycle Detection Algorithm (tortoise and hare approach)
 * @head: A pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *loop_start = detect_loop(head);

	if (!loop_start)
	{
		return (print_list(head, NULL));
	}
	else
	{
		return (print_list(head, loop_start));
	}
}
