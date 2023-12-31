#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {770, 740, 729, 406, 671, 26, 879, 877, 625, 281, 277, 126, 906, 453, 374, 245, 549, 13, 184, 108, 485, 472, 127, 513, 786, 719, 660, 707, 435, 3, 641, 238, 392, 769, 645, 276, 459, 962, 9, 895, 370, 339, 208, 188, 257, 726, 883, 751, 971, 483, 138, 560, 220, 454, 57, 717, 939, 522, 173, 755, 484, 612, 466, 212, 450, 243, 829, 100, 104, 898, 95, 160, 289, 613, 914, 328, 853, 30, 114, 123, 298, 167, 172, 290, 446, 716, 349, 16, 999, 312, 864, 163, 753, 763, 627, 258, 369, 429, 96, 401};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
