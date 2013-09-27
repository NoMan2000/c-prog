/*
 *      increment2.c
 *
 *      Program to demonstrate multi-dimensional arrays
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     grid[18][18];
    int     i, j;

    for (i = 0; i < 18; i++)
        for (j = 0; j < 18; j++)
            grid[i][j] = (i+1) * (j+1);

    for (i = 0; i < 18; i++)
    {
        for (j = 0; j < 18; j++)
            printf("%3d ", grid[i][j]);
        printf("\n");
    }

    fflush(stdin);
    getchar();
}

