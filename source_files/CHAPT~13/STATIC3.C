/*
 *      static3.c
 *
 *      Program to demonstrate the use of local static variables
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

func()
{
    static int  called_already = 0;

    if (!called_already)
        printf("This is the first (and hopefully only) time func is called\n");
    called_already = 1;
}

main()
{
    func();
    func();
    func();
    func();
    func();

    fflush(stdin);
    getchar();
}

