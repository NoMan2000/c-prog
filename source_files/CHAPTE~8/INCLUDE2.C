/*
 *      include2.c
 *
 *      Program to demonstrate the use of the #include directive
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <string.h>
#include "maximums.h"

main()
{
    char    name[NAME_SIZE + 1];
    int     length;

    printf("Please enter your name: ");
    scanf("%s", name);

    length = strlen(name);
    printf("Length of >>%s<< is %d\n", name, length);

    fflush(stdin);
    getchar();
}

