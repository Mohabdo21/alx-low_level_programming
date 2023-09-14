#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_numbers - Prints numbers,
 * separated by a separator, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (separator != NULL && i < n - 1)
		printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}

