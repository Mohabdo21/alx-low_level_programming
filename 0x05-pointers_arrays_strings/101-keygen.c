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
	char password[9]; /* Password length is 5 characters */

	srand(time(NULL)); /* Initialize random number generator with current time */

	for (i = 0; i < 1000000; i++) /* Generate 1000000 passwords */
	{
		for (j = 0; j < 8; j++) /* Generate 5 characters for the password */
		{
			password[j] = rand() % ('z' - '!' + 1) + '!'; /* '!' to 'z' inclusive */
		}

		password[9] = '\0'; /* Null-terminate the password */

		printf("%s\n", password);
	}

	return (0);
}
