/*
 *      ifdef.c
 *
 *      Program to demonstrate the #ifdef directive
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

#define GRID_SIZE   16

main()
{
    int     grid[GRID_SIZE][GRID_SIZE];
    int     i, j;

    /*
     *  first, perform the calculations
     */
    for (i = 0; i < GRID_SIZE; i++)
        for (j = 0; j < GRID_SIZE; j++)
            grid[i][j] = (i+1) * (j+1);     /* simple multiply */

#ifdef PRINTING
    /*
     *  Next, print the results
     */
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
            printf("%3d ", grid[i][j]);
        printf("\n");          /* print a newline at the end of every row */
    }
#endif

    fflush(stdin);
    getchar();
}

