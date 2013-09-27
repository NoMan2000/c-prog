/*
 *      increment.c
 *
 *      Program to illustrate the use of the increment
 *      and decrement operators
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x, y, z = 1;

    y = 5;
    x = 6;
    z = x+++++y;

    printf("x = %d, y = %d, z = %d\n", x, y, z);

    fflush(stdin);
    getchar();
}

