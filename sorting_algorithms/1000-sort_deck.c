#include "deck.h"

/**
 * _strcmp - Compares two strings
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 *
 * Return: An integer indicating the relationship between the strings:
 *         0 if the strings are equal,
 *         a negative number if str1 < str2,
 *         a positive number if str1 > str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return ((int)((unsigned char)*str1 - (unsigned char)*str2));
}

/**
 * get_card_value_index - Get the index of the card value
 * @value: The value of the card
 *
 * Return: The index of the card value, or -1 if the value is not valid
 */
int get_card_value_index(const char *value)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
		"Jack", "Queen", "King"};
	int i;

	for (i = 0; i < NUM_VALUES; i++)
	{
		if (_strcmp(values[i], value) == 0)
			return (i);
	}
	return (-1);
}

/**
 * distribute_cards - Distribute cards into buckets
 * @deck: A pointer to the deck of cards
 * @buckets: A 2D array of pointers to the deck nodes
 * @tail: A 2D array of pointers to the last node in each bucket
 * Return: 0 On Success or -1 for invalid card value
 */
int distribute_cards(deck_node_t **deck,
		deck_node_t *buckets[NUM_SUITS][NUM_VALUES],
		deck_node_t *tail[NUM_SUITS][NUM_VALUES])
{
	deck_node_t *node, *next_node;
	int value_index;

	for (node = *deck; node; node = next_node)
	{
		/* Store the next node since we modify node->next in the process */
		next_node = node->next;

		value_index = get_card_value_index(node->card->value);
		if (value_index == -1)
		{
			/* If the card's value is invalid, print an error message and return */
			fprintf(stderr, "Error: Invalid card value '%s'\n", node->card->value);
			return (-1);
		}
		if (!buckets[node->card->kind][value_index])
		{
			buckets[node->card->kind][value_index] = node;
			tail[node->card->kind][value_index] = node;
		}
		else
		{
			tail[node->card->kind][value_index]->next = node;
			node->prev = tail[node->card->kind][value_index];
			tail[node->card->kind][value_index] = node;
		}
		/* Unlink the node from the original deck */
		node->next = NULL;
	}
	return (0);
}

/**
 * collect_and_relink_cards - Collect cards from buckets and relink them
 * @deck: A pointer to the deck of cards
 * @buckets: A 2D array of pointers to the deck nodes
 * @tail: A 2D array of pointers to the last node in each bucket
 */
void collect_and_relink_cards(deck_node_t **deck,
		deck_node_t *buckets[NUM_SUITS][NUM_VALUES],
		deck_node_t *tail[NUM_SUITS][NUM_VALUES])
{
	deck_node_t *head = NULL, *end = NULL;
	int i, j;

	for (i = 0; i < NUM_SUITS; i++)
	{
		for (j = 0; j < NUM_VALUES; j++)
		{
			if (buckets[i][j])
			{
				if (!head)
				{
					head = buckets[i][j];
					end = tail[i][j];
				}
				else
				{
					end->next = buckets[i][j];
					buckets[i][j]->prev = end;
					end = tail[i][j];
				}
			}
		}
	}
	/* Update deck pointer to the first node of the sorted deck */
	*deck = head;
}

/**
 * sort_deck - Sort a deck of cards using Bucket sort
 * @deck: A pointer to the deck of cards
 *
 * This function sorts a deck of cards in ascending order first by suit
 * (Spade, Heart, Club, Diamond) and then by value (Ace to King).
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *buckets[NUM_SUITS][NUM_VALUES] = {NULL};
	deck_node_t *tail[NUM_SUITS][NUM_VALUES] = {NULL};

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	if (distribute_cards(deck, buckets, tail) == -1)
	{
		fprintf(stderr, "Error: Failed to distribute cards\n");
		return;
	}

	collect_and_relink_cards(deck, buckets, tail);
}
