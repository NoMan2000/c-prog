/*
 *      static1.c
 *
 *      The first of two files used to answer the chapter 14
 *      exercise on two functions with identical names
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int  count;

static initialise()
{
    count = 100;
}

main()
{
    initialise();
    func();

    printf("The value of count is %d\n", count);

    fflush(stdin);
    getchar();
}

