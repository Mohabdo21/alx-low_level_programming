#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Define the number of suits and card values */
#define NUM_SUITS 4
#define NUM_VALUES 13

/**
 * enum kind_e - Enumeration of the kinds of a playing card
 *
 * @SPADE: Represents the Spade suit
 * @HEART: Represents the Heart suit
 * @CLUB: Represents the Club suit
 * @DIAMOND: Represents the Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototypes */
int _strcmp(const char *str1, const char *str2);
int get_card_value_index(const char *value);
void sort_deck(deck_node_t **deck);
void print_deck(const deck_node_t *deck);
deck_node_t *init_deck(const card_t cards[52]);
void free_deck(deck_node_t *deck);
int distribute_cards(deck_node_t **deck,
		deck_node_t *buckets[NUM_SUITS][NUM_VALUES],
		deck_node_t *tail[NUM_SUITS][NUM_VALUES]);
void collect_and_relink_cards(deck_node_t **deck,
		deck_node_t *buckets[NUM_SUITS][NUM_VALUES],
		deck_node_t *tail[NUM_SUITS][NUM_VALUES]);


#endif /* DECK_H */
