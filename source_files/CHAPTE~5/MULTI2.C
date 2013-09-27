/*
 *      multi2.c
 *
 *      Program to demonstrate multi-dimensional arrays
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    strings[5][20];
    int     i;

    for (i = 0; i < 5; i = i + 1)
    {
        printf("Please enter string %d: ", i+1);
        scanf("%s", strings[i]);
    }

    for (i = 0; i < 5; i = i + 1)
        printf("String %d is %s\n", i+1, strings[i]);
    printf("String 4 Character 2 is %c\n", strings[3][1]);

    fflush(stdin);
    getchar();
}

