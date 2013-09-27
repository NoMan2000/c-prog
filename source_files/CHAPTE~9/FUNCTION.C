/*
 *      function.c
 *
 *      Program to illustrate the use of simple functions
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

#define GRID_SIZE   16

times_table()
{
    int     grid[GRID_SIZE][GRID_SIZE];
    int     i, j;

    /*
     *  first, perform the calculations
     */
    for (i = 0; i < GRID_SIZE; i++)
        for (j = 0; j < GRID_SIZE; j++)
            grid[i][j] = (i+1) * (j+1);     /* simple multiply */

    /*
     *  Next, print the results
     */
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
            printf("%3d ", grid[i][j]);
        printf("\n");          /* print a newline at the end of every row */
    }
}

add()
{
    int     num1, num2;
    int     total;

    printf("Please enter the first number:  ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    total = num1 + num2;

    printf("The total of the two numbers is %d\n", total);
}

run_it()
{
    add();
    printf("Add has been run\n");
}

main()
{
    char    answer[20];

    printf("What would you like to do? (type \"times\" or \"add\"): ");
    scanf("%s", answer);

    if (strcmp(answer, "times") == 0)
        times_table();
    else if (strcmp(answer, "add") == 0)
        run_it();
    else
        printf("I don't know what you want to do\n");

    fflush(stdin);
    getchar();
}

