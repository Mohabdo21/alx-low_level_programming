#include "main.h"
#include <stdio.h>

/**
 * positive_or_negative - determint which
 * number is bigger
 * i - the well checked
 */

void positive_or_negative(int i)
{

if (i > 0)
	printf("%d is positive\n", i);
	else if (i == 0)
	printf("%d is zero\n", i);
	else
	printf("%d is negative\n", i);

}
