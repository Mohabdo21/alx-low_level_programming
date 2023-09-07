#include <stdio.h>
#include <stdlib.h>

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int str_to_int(char *str)
{
	int result, sign, i;

	result = 0;
	sign = 1;
	i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (str[i] != '\0')
	{
		if (!is_digit(str[i]))
		{
			printf("Error\n");
			exit(98);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int main(int argc, char *argv[])
{
	int num1, num2;
	long result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = str_to_int(argv[1]);
	num2 = str_to_int(argv[2]);
	result = (long)num1 * num2;

	if (result < 0)
	{
		printf("Error\n");
		return (98);
	}

	printf("%ld\n", result);
	return (0);
}

