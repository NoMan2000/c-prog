/*
 *      pointer3.c
 *
 *      Program to demonstrate the correct use of pointers
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x;
    int     y;
    char    *ptr;

    /*
     *  Find out the current memory address of x and y.
     *  Note:  You don't need to use the pointer "ptr" to do this.
     *  Hint:  Memory addresses are 32 bit values, so are integers (probably)
     */
    printf("The memory address of x is %d\n", &x);
    printf("The memory address of y is %d\n", &y);

    /*
     *  "ptr" is currently uninitialised
     *  Find out the current random character it is pointing to
     *  (and the address of this character)
     *  Note:  This could possibly crash your program
     */
    printf("The current random address in ptr is %d\n", ptr);
    /* printf("The random character ptr is pointing to is %c\n", *ptr); */

    fflush(stdin);
    getchar();
}

