/*
 *      print_int.c
 *
 *      Program to solve the print_int macro problem from chapter 9
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

/*
 *  A macro to print one integer
 */
#define print_int(a)    printf("%d", a)

main()
{
    int     x = 10;

    fputs("The value of x is ", stdout);
    print_int(x);
    puts("");           /* newline */

    fflush(stdin);
    getchar();
}

