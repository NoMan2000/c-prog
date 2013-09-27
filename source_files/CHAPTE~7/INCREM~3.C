/*
 *      increment3.c
 *
 *      Program to illustrate increment operators
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    name[51];
    char    name2[51];
    int     i = 0;

    printf("Please enter your name: ");
    scanf("%s", name);

    /*
     *  I don't like this code awfully much
     */
    while (name[i])
        name2[i++] = name[i];

    printf("name2 is >>>%s<<<\n", name2);

    fflush(stdin);
    getchar();
}

