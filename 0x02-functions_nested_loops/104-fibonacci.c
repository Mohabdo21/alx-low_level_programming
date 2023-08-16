#include <stdio.h>

#define MAX_DIGITS 1000

typedef struct
{
	int digits[MAX_DIGITS];
}
BigInt;

void initBigInt(BigInt *num)
{
	int i;
	for (i = 0; i < MAX_DIGITS; i++) {
	num->digits[i] = 0;
	}
}

void addBigInt(BigInt *result, const BigInt *a, const BigInt *b)
{
	int carry = 0;
	int i;
	for (i = MAX_DIGITS - 1; i >= 0; i--) {
		int sum = a->digits[i] + b->digits[i] + carry;
		result->digits[i] = sum % 10;
		carry = sum / 10;
	}
}

void copyBigInt(BigInt *dest, const BigInt *src) {
	int i;

	for (i = 0; i < MAX_DIGITS; i++)
	{
	dest->digits[i] = src->digits[i];
	}
}

void printBigInt(const BigInt *num)
{
	int leadingZeroes = 1;
	int i;

	for (i = 0; i < MAX_DIGITS; i++) {
	if (leadingZeroes && num->digits[i] != 0)
	{
		leadingZeroes = 0;
	}
	if (!leadingZeroes)
		{
		printf("%d", num->digits[i]);
		}
	}
}

int main(void) {

/**
 *
 *  main - Entry point of the program
 *
 *  Return: 0 Always (Success)
 */
	int count;

	BigInt n1, n2, next;
	initBigInt(&n1);
	initBigInt(&n2);
	initBigInt(&next);

	n1.digits[MAX_DIGITS - 1] = 1;
	n2.digits[MAX_DIGITS - 1] = 2;

	for (count = 2; count < 98; count++)
	{
	addBigInt(&next, &n1, &n2);

	printf(", ");
	printBigInt(&next);

	copyBigInt(&n1, &n2);
	copyBigInt(&n2, &next);
	}

	printf("\n");

	return (0);
}
