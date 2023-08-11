#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* betty style doc for function main goes there 
 * 
 * The main function check random number 
 *
 * and check if it Positive or Nigative
 *
 * Return: Always 0 (Success)
 *
 * */
int main(void)
{
	int n;
	int last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit = n % 10;  /* Calculate the last digit of n */

    printf("Last digit of %d is %d", n, last_digit);

    if (last_digit > 5) {
        printf(" and is greater than 5\n");
    } else if (last_digit == 0) {
        printf(" and is 0\n");
    } else {
        printf(" and is less than 6 and not 0\n");
    }
	return (0);
}
