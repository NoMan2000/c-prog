/*
 *      cast.c
 *
 *      Program to illustrate the use of the "cast"
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int	    x = 13;

    printf("x/2 is %.2f\n", (float)x / 2);

    printf("x/2 is %d\n", x / 2);
    printf("x/2 is %.2f\n", (float)(x / 2));

    printf("x/2 is %.2f\n", x / 2.0);

    fflush(stdin);
    getchar();
}

