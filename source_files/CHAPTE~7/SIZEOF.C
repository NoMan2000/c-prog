/*
 *      sizeof.c
 *
 *      Program to demonstrate the sizeof operator
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x;
    short   arr[20];
    double  y;
    char    string[51];

    printf("The size of x (an integer) is %d bytes\n", sizeof x);
    printf("The size of arr (an array of 20 shorts) is %d bytes\n",
                                 sizeof arr);
    printf("The size of one element of arr (one short) is %d bytes\n",
                                 sizeof arr[0]);
    printf("The size of y (a double) is %d bytes\n", sizeof y);
    printf("The size of string (an array of 51 chars) is %d bytes\n",
                                 sizeof string);
    printf("The size of one element of string (one char) is %d bytes\n",
                                 sizeof string[0]);
    printf("The size of a long is %d bytes\n", sizeof(long));

    fflush(stdin);
    getchar();
}

