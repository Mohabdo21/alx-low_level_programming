#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		/* swap the root of the heap with the last element */
		swap(array, 0, end);
		print_array(array, size);

		/* sift down the root element to restore the heap property */
		end--;
		sift_down(array, 0, end, size);
	}
}

/**
 * heapify - transforms an array into a heap
 * @array: array to be transformed into a heap
 * @size: size of the array
 *
 * This function transforms an array into a heap by repeatedly
 * sifting down elements from the end of the array to the start.
 * The sift down operation ensures that the heap property is
 * maintained for all elements in the array.
 */
void heapify(int *array, size_t size)
{
	int start;

	/* Start with the last parent node */
	start = (size - 2) / 2;

	/* Sift down all nodes from the last parent to the root */
	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * sift_down - repairs the heap whose root element is at index 'start'
 * @array: array representing the heap
 * @start: root of the heap
 * @end: last index of the heap
 * @size: size of the array
 *
 * This function repairs a heap whose root element violates the heap property.
 * It does this by repeatedly swapping the root with its largest child until
 * the heap property is restored.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child;

	root = start;

	/* While the root has at least one child */
	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		/**
		* If the child has a sibling and the child's
		* value is less than its sibling's
		*/
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		/* If the root's value is less than the child's */
		if (array[root] < array[child])
		{
			/* Swap the root with the child */
			swap(array, root, child);
			print_array(array, size);
			/* Repeat to continue sifting down the child now */
			root = child;
		}
		else
			return;
	}
}

/**
 * swap - swaps two elements in an array
 * @array: array containing the elements to be swapped
 * @i: index of the first element
 * @j: index of the second element
 */
void swap(int *array, size_t i, size_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
}
