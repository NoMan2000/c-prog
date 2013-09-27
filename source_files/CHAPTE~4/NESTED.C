/*
 *      nested.c
 *
 *      Program to demonstrate the use of nested loops
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     i, j;

    for (i = 1; i <= 5; i = i + 1)
        for (j = 1; j <= 3; j = j + 1)
            printf("Here we are in the inner loop with i=%d and j=%d\n",
                                                     i, j);

    fflush(stdin);
    getchar();
}

