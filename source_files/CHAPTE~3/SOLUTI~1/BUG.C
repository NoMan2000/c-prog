/*
 *      bug.c
 *
 *      Program to test if you can debug some code
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x = 1;

    if (x == 1)
        printf("x equals 1\n");
    else
        printf("x does not equal 1\n");

    fflush(stdin);
    getchar();
}

