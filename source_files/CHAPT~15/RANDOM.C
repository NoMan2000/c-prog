/*
 *      random.c
 *
 *      Program to demonstrate the use of rand() and srand()
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
    int     i;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
        printf("Random number #%2d is : %6d\n", i+1, rand());

    fflush(stdin);
    getchar();

    return 0;
}

