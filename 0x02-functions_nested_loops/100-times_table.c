#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 * Return: On success, 1. On error, -1 is returned
 */
int _putchar(char c);

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    if (n >= 10)
        print_number(n / 10);

    _putchar((n % 10) + '0');
}

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The times table to print
 */
void print_times_table(int n)
{
    int i;
   int j;
  int result;
    if (n > 15 || n < 0)
        return;


    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            result = i * j;
            if (j != 0)
            {
                _putchar(',');
                _putchar(' ');
                if (result < 10)
                    _putchar(' ');
                if (result < 100)
                    _putchar(' ');
            }

            print_number(result);

            if (j == n)
                _putchar('\n');
        }
    }
}

