/*
 *      multi3.c
 *
 *      Program to demonstrate initialising multi-dimensional arrays
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    grid[8][8] =
    {
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}
    };
    int     i, j;


    for (i = 0; i < 8; i = i + 1)
    {
        for (j = 0; j < 8; j = j + 1)
            printf("%c ", grid[i][j]);
        printf("\n");
    }

    fflush(stdin);
    getchar();
}

