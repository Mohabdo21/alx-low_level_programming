#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if 'c' is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	printf("Error\n");
	return (98);
}

/**
 * multiply_large_numbers - Multiplies two
 * large numbers represented as strings.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 *
 * Return: A dynamically allocated string containing the product.
 *         The caller is responsible for freeing the memory.
 */
char *multiply_large_numbers(char *num1, char *num2)
{
	int len1, len2, result_len;
	int i, carry, j, product;
	int leading_zeros;
	char *result;

	len1 = strlen(num1);
	len2 = strlen(num2);

	result_len = len1 + len2;
	result = (char *)malloc((result_len + 1) * sizeof(char));

	if (result == NULL)
	{
		printf("Error: Memory allocation failed\n");
		exit(1);
	}
	memset(result, '0', result_len);
	result[result_len] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
		product = (num1[i] - '0') * (num2[j] - '0') +
			(result[i + j + 1] - '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}
		result[i] += carry;
	}
	leading_zeros = 0;
	while (result[leading_zeros] == '0' && result[leading_zeros + 1] != '\0')
	{
		leading_zeros++;
	}
	if (leading_zeros > 0)
	{
		memmove(result, result + leading_zeros, result_len - leading_zeros + 1);
	}
	return (result);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 if successful, 98 if there are incorrect
 * arguments or invalid characters in the input.
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;
	char *result;
	unsigned long int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; i < strlen(num1); i++)
	{
		if (!is_digit(num1[i]))
		{
			printf("Error\n");
			return (98);
		}
	}

	for (j = 0; j < strlen(num2); j++)
	{
		if (!is_digit(num2[j]))
		{
			printf("Error\n");
			return (98);
		}
	}

	result = multiply_large_numbers(num1, num2);

	printf("%s\n", result);

	free(result);

	return (0);
}
