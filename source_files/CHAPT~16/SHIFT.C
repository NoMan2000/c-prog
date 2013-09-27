/*
 *      shift.c
 *
 *      Program to demonstrate the shift left and right operators
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>

static void goodbye()
{
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

main()
{
    unsigned int     number;
    int              shift;
    unsigned int     result;

    atexit(goodbye);

    printf("Please enter a number: ");
    scanf("%d", &number);
    printf("How many bits would you like to shift (negative to shift right)? ");
    scanf("%d", &shift);

    if (shift >= 0)
        result = number << shift;
    else
        result = number >> -shift;

    printf("%u (hex %X) shifted %s %d is %u (hex %X)\n",
            number, number,
            shift >= 0 ? "left" : "right",
            shift >= 0 ? shift : -shift,
            result, result);

    return 0;
}

