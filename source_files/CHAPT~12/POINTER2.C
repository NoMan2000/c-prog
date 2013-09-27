/*
 *      pointer2.c
 *
 *      Program to demonstrate the correct use of pointers
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    float   f;
    float   *ptr;

    /*
     *  Assign the value of 3.5 to f
     *  without using a statement that begins "f = "
     */
    ptr = &f;
    *ptr = 3.5;

    printf("The value of f is %f\n", f);

    fflush(stdin);
    getchar();
}

