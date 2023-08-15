#include <stdio.h>
#include "main.h"

int main(void)
{
	int limit = 1024;
	int sum = calculate_multiples_sum(limit);

	printf("%d\n", sum);

	return (0);
}
