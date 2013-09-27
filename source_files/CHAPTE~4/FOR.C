/*
 *      for.c
 *
 *      Program to demonstrate the use of the for loop
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     counter;
    int     total = 0;

    for (counter = 1; counter <= 1000; counter = counter + 1)
        total = total + counter;

    printf("The sum of all numbers from 1 to 1000 is %d\n", total);

    fflush(stdin);
    getchar();
}

