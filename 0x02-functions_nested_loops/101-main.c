#include "main.h"

int calculate_multiples_sum(int limit)
{
    int sum = 0;
	int i;
    for (i = 0; i < limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }

    return (sum);
}
