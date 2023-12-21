#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*-------------------- MACROS ------------------------*/
#define BASE10 10

/*-------------------- ENUMS ------------------------*/
/**
 * enum kind_e - enums for cards' types
 * @SPADE: value 0
 * @HEART: value 1
 * @CLUB: value 2
 * @DIAMOND: value 3
 *
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/*-------------------- STRUCTS ------------------------*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

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

/*------------------ SORTING ALGORITHMS ---------------------*/
void insertion_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);

/*-------------------- HELPERS ------------------------*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void _qsort(int *arr, int lo, int hi, size_t size);
int partition(int *arr, int lo, int hi, size_t size);
void swap(int *array, size_t i, size_t j);
void td_merge(int *b, int start, int mid, int end, int *a);
void td_split(int *a, int start, int end, int *b);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void heapify(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void base_sort(int *input, int *output, size_t size, int max, int expo);
int _pow(int b, int e);
void qsort_Hoare(int *arr, int lo, int hi, size_t size);
int partition_Hoare(int *arr, int lo, int hi, size_t size);
void bmerge(int *arr, int low, size_t count, int dir, size_t size);
void bsort(int *arr, int low, size_t count, int dir, size_t size);

#endif /* HEADER */
