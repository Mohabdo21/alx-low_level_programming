#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

/**
 * linear_search - Searches for a value in an array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located,
 * or -1 if value is not present
 */
int linear_search(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
