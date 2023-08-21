#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point , Generates random valid passwords for the program 101-crackme.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int j;
	char password[33]; /* Password length is 32 characters */

	srand(time(NULL)); /* Initialize random number generator with current time */

	for (i = 0; i < 1000000; i++) /* Generate 1000000 passwords */
	{
		for (j = 0; j < 32; j++) /* Generate 32 characters for the password */
		{
			password[j] = rand() % ('z' - '!' + 1) + '!'; /* '!' to 'z' inclusive */
		}

		password[33] = '\0'; /* Null-terminate the password */

		printf("%s", password);
		break;
	}

	return (0);
}
