/*
 *      malloc.c
 *
 *      Program to demonstrate the use of the malloc library function
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>     /* provides prototypes for malloc and free */
                        /* (among other things) */
main()
{
    int     *integers;
    int     required = 3;
    int     i;

    integers = malloc(required * sizeof(int));
    if (integers == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    for (i = 0; i < required; i++)
    {
        printf("Please enter number #%d: ", i+1);
        fflush(stdin);
        scanf("%d", &integers[i]);
    }

    for (i = 0; i < required; i++)
        printf("Number #%d was %d\n", i+1, integers[i]);

    fflush(stdin);
    getchar();
}

