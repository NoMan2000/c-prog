/*
 *      funcptrs.c
 *
 *      Program to demonstrate the use of function pointers
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

static int add(int a, int b)
{
    return a + b;
}

static int subtract(int x, int y)
{
    return x - y;
}

main()
{
    int     i, j;
    int     result;
    int     (*func_ptr)(int, int);

    atexit(goodbye);

    printf("Please enter the first number:  ");
    scanf("%d", &i);
    printf("Please enter the second number: ");
    scanf("%d", &j);

    printf("Would you like to add or subtract (a/s)? ");
    fflush(stdin);

    if (getchar() == 'a')
        func_ptr = add;
    else
        func_ptr = subtract;

    result = func_ptr(i, j);

    printf("The result is %d\n", result);

    return 0;
}

