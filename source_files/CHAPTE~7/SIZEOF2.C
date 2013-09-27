/*
 *      sizeof2.c
 *
 *      Program to demonstrate the use of the sizeof operator
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     array[] =
        {1, 34, 65, 778, 111, 23, 782, 75, 94, 3, 100, 22, 58, 145, 72, 99,
         43, 67, 278, 98, 53};
    int     total = 0;
    float   average;
    int     i;

    for (i = 0; i < sizeof array / sizeof array[0]; i++)
        total += array[i];

    average = total / (sizeof array / sizeof array[0]);

    printf("The total is %d\n", total);
    printf("The average is %.3f\n", average);

    fflush(stdin);
    getchar();
}

