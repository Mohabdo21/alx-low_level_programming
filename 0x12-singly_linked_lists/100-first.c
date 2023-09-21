#include <stdio.h>

void tortoise_message(void) __attribute__((constructor));

/**
 * tortoise_message - printd the message before main
 */
void tortoise_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
