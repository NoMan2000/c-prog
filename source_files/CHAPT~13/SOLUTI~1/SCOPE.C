/*
 *      scope.c
 *
 *      Program to show three variables visible in the same place
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int  x = 100;

main()
{
    float   x = 200.0;

    if (x > 150)
    {
        int     x = 300;

        printf("The value of x is %d\n", x);
    }

    fflush(stdin);
    getchar();
}

