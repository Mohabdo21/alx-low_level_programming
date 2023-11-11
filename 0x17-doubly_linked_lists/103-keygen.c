#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * calculate_case_1 - Performs a specific calculation
 * based on the given argument.
 *
 * @arg2: The argument to be used in the calculation.
 * Return: The result of the calculation.
 */
uint64_t calculate_case_1(int32_t arg2)
{
	return ((arg2 ^ 0x3b) & 0x3f);
}

/**
 * calculate_case_2 - Calculates the sum of the
 * elements in the given array.
 *
 * @arg1: Pointer to the array.
 * @arg2: The number of elements in the array.
 * Return: The result of the calculation.
 */
uint64_t calculate_case_2(void *arg1, int32_t arg2)
{
	int32_t var_10 = 0;
	int i;

	for (i = 0; i < arg2; i++)
	{
		var_10 = (var_10 + *((char *)arg1 + i));
	}
	return ((var_10 ^ 0x4f) & 0x3f);
}

/**
 * calculate_case_3 - Calculates the product of the
 * elements in the given array.
 *
 * @arg1: Pointer to the array.
 * @arg2: The number of elements in the array.
 * Return: The result of the calculation.
 */
uint64_t calculate_case_3(void *arg1, int32_t arg2)
{
	int32_t var_10 = 1;
	int i;

	for (i = 0; i < arg2; i++)
	{
		var_10 = (*((char *)arg1 + i) * var_10);
	}
	return ((var_10 ^ 0x55) & 0x3f);
}

/**
 * calculate - Performs a calculation based on the operation code.
 *
 * @operation: The operation code.
 * @arg1: Pointer to the array (used in some operations).
 * @arg2: The number of elements in the array or a
 * specific value (used in some operations).
 * Return: The result of the calculation.
 */
uint64_t calculate(int operation, void *arg1, int32_t arg2)
{
	int32_t var_10 = 0;
	int32_t i;
	int32_t rax_12;

	switch (operation)
	{
		case 1:
			return (calculate_case_1(arg2));
		case 2:
			return (calculate_case_2(arg1, arg2));
		case 3:
			return (calculate_case_3(arg1, arg2));
		case 4:
			var_10 = *((char *)arg1);
			for (i = 0; i < arg2; i = (i + 1))
			{
				if (*((char *)arg1 + i) > var_10)
				{
					var_10 = *((char *)arg1 + i);
				}
			}
			srand((var_10 ^ 0xe));
			return (rand() & 0x3f);
		case 5:
			for (i = 0; i < arg2; i = (i + 1))
			{
				var_10 = (var_10 + (*((char *)arg1 + i) * *((char *)arg1 + i)));
			}
			rax_12 = (var_10 ^ 0xef);
			return (rax_12 & 0x3f);
		case 6:
			for (i = 0; *((char *)arg1) > i; i = (i + 1))
			{
				var_10 = rand();
			}
			rax_12 = (var_10 ^ 0xe5);
			return (rax_12 & 0x3f);
		default:
			return (0);
	}
}

/**
 * main - The main function of the program.
 *
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 * Return: 0 if the program finishes successfully, 1 otherwise.
 */
int main(int argc, char **argv)
{
	char *username;
	int32_t len;
	char key[7];

	if (argc != 2)
	{
		printf("Usage: ./keygen5 username\n");
		return (1);
	}

	username = argv[1];
	len = strlen(username);

	key[0] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(1, NULL, len)];
	key[1] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(2, username, len)];
	key[2] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(3, username, len)];
	key[3] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(4, username, len)];
	key[4] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(5, username, len)];
	key[5] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[calculate(6, username, 1)];
	key[6] = '\0';

	printf("%s\n", key);

	return (0);
}
