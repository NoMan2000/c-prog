/*
 *      array.c
 *
 *      Program to illustrate the use of arrays
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    float   array[5];
    int     i;
    int     index;

    for (i = 0; i < 5; i = i + 1)
    {
        printf("Please enter element number %d: ", i+1);
        fflush(stdin);
        scanf("%f", &array[i]);
    }

    printf("Which element do you want to see? ");
    fflush(stdin);
    scanf("%d", &index);

    printf("Element %d is %f\n", index, array[index-1]);

    fflush(stdin);
    getchar();
}

