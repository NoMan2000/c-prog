/*
 *      while.c
 *
 *      Program to demonstrate the use of the while loop
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    type = 'x';
    int     album;          /* boolean */

    while (type != 'a' && type != 's')
    {
        printf("Album or single (a for album, s for single)? ");
        fflush(stdin);
        scanf("%c", &type);
        album = type == 'a';
        if (type != 'a' && type != 's')
            printf("Error\n");
    }

    if (album)
        printf("Album\n");
    else
        printf("Single\n");

    fflush(stdin);
    getchar();
}

