/*
 *      while2.c
 *
 *      Program to demonstrate the use of the while loop
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     counter = 1;
    int     total = 0;

    while (counter <= 1000)
    {
        total = total + counter;
        counter = counter + 1;
    }

    printf("The sum of all numbers from 1 to 1000 is %d\n", total);

    fflush(stdin);
    getchar();
}

