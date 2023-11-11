#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * f1 - Computes a value based on the input argument.
 *
 * @arg1: The input argument, an integer.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f1(int32_t arg1)
{
	return ((arg1 ^ 0x3b) & 0x3f);
}

/**
 * f2 - Computes a value based on the input arguments.
 *
 * @arg1: A pointer to the input data.
 * @arg2: The length of the input data.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f2(void *arg1, int32_t arg2)
{
	int32_t var_10 = 0;
	int32_t i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (var_10 + *((char *)arg1 + i));
	}
	return ((var_10 ^ 0x4f) & 0x3f);
}

/**
 * f3 - Computes a value based on the input arguments.
 *
 * @arg1: A pointer to the input data.
 * @arg2: The length of the input data.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f3(void *arg1, int32_t arg2)
{
	int32_t var_10 = 1;
	int32_t i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (*((char *)arg1 + i) * var_10);
	}
	return ((var_10 ^ 0x55) & 0x3f);
}

/**
 * f4 - Computes a value based on the input arguments.
 *
 * @arg1: A pointer to the input data.
 * @arg2: The length of the input data.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f4(char *arg1, int32_t arg2)
{
	int32_t var_10 = *arg1;
	int32_t i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		if (arg1[i] > var_10)
		{
			var_10 = arg1[i];
		}
	}
	srand((var_10 ^ 0xe));
	return (rand() & 0x3f);
}

/**
 * f5 - Computes a value based on the input arguments.
 *
 * @arg1: A pointer to the input data.
 * @arg2: The length of the input data.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f5(void *arg1, int32_t arg2)
{
	int32_t var_10 = 0;
	int32_t i;
	int32_t rax_12;

	for (i = 0; i < arg2; i = (i + 1))
	{
		var_10 = (var_10 + (*((char *)arg1 + i) * *((char *)arg1 + i)));
	}
	rax_12 = (var_10 ^ 0xef);
	return (rax_12 & 0x3f);
}

/**
 * f6 - Computes a value based on the input argument.
 *
 * @arg1: The input argument, a character.
 *
 * Return: The computed value, a 64-bit unsigned integer.
 */
uint64_t f6(char arg1)
{
	int32_t var_10 = 0;
	int32_t i;
	int32_t rax_3;

	for (i = 0; arg1 > i; i = (i + 1))
	{
		var_10 = rand();
	}
	rax_3 = (var_10 ^ 0xe5);
	return (rax_3 & 0x3f);
}

/**
 * main - The main function of the program.
 * It takes a username as an argument and
 * generates a key based on the username.
 *
 * @argc: The number of command-line arguments.
 * @argv: The command-line arguments.
 *
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
		[f1(len)];
	key[1] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[f2(username, len)];
	key[2] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[f3(username, len)];
	key[3] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[f4(username, len)];
	key[4] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[f5(username, len)];
	key[5] = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
		[f6(*username)];
	key[6] = '\0';

	printf("%s\n", key);

	return (0);
}
