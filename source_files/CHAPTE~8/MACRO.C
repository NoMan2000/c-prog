/*
 *      macro.c
 *
 *      Program to demonstrate a #define macro
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

#define Max(a, b)       ((a) > (b) ? (a) : (b))
#define Double(s)       ((s) * 2)

main()
{
    int     x, y, z;

    x = 6;
    y = 7;
    z = Max(x, y);
    z = Double(x+1);

    printf("Double x is %d\n", z);

    fflush(stdin);
    getchar();
}

