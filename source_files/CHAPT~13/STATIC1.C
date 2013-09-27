/*
 *      static1.c
 *
 *      The first of two files used to demonstrate the
 *      concept of static variables and functions
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int  count;

func1()
{
    count = 1;
}

main()
{
    func1();
    func2();

    printf("The value of count is %d\n", count);

    fflush(stdin);
    getchar();
}

