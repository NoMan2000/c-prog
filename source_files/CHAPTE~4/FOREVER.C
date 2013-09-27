/*
 *      forever.c
 *
 *      Program to demonstrate the use of the "forever" loop
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    type;
    int     album;          /* boolean */

    for (;;)
    {
        printf("Album or single (a for album, s for single)? ");
        fflush(stdin);
        scanf("%c", &type);
        if (type == 'a' || type == 's')
            break;
        printf("Error\n");
    }
    album = type == 'a';

    if (album)
        printf("Album\n");
    else
        printf("Single\n");

    fflush(stdin);
    getchar();
}

