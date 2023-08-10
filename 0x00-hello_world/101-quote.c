#include <unistd.h>

/**
 * main - Entry point of the program
 *
 *
 * The function print a text without using, printf or puts.
 *
 * Return: Always 1 (Success)
 */
int main(void)
{
    write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 59);
    return 1;
}
