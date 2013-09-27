/*
 *      double.c
 *
 *      Program to demonstrate the use of
 *      function parameters that are memory addresses
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

double_it(int *ptr)
{
    *ptr = *ptr * 2;
}

main()
{
    int     num1;

    printf("Please enter the number: ");
    scanf("%d", &num1);

    double_it(&num1);

    printf("The doubled value is %d\n", num1);

    fflush(stdin);
    getchar();
}

