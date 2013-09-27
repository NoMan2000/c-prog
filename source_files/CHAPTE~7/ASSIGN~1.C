/*
 *      assignment.c
 *
 *      Program to demonstrate the use of assignment operators
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x, y;

    y = 3;
    x = 100;
    x /= y - 1;

    printf("x = %d\n", x);

    fflush(stdin);
    getchar();
}

