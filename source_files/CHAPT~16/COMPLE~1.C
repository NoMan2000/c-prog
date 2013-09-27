/*
 *      complement.c
 *
 *      Program to demonstrate the ones complement (~) operator
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
    unsigned long     number;       /* we shall use 8-bit demonstrations */
    unsigned long     result;

    atexit(goodbye);

    printf("Please enter a number: ");
    scanf("%d", &number);

    result = ~number;

    printf("The ones complement of %u (hex %X) is %u (hex %X)\n",
            number, number, result, result);

    return 0;
}

