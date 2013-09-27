/*
 *      free.c
 *
 *      Program to demonstrate the use of the malloc library function
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>     /* provides prototypes for malloc and free */
                        /* (among other things) */

#define REQUIRED    3   /* number of integers required */

int *allocate_the_memory()
{
    int     *ptr;

    ptr = malloc(REQUIRED * sizeof(int));
    if (ptr == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }
    return ptr;
}

use_the_memory(int *integers)
{
    int     i;

    for (i = 0; i < REQUIRED; i++)
    {
        printf("Please enter number #%d: ", i+1);
        fflush(stdin);
        scanf("%d", &integers[i]);
    }

    for (i = 0; i < REQUIRED; i++)
        printf("Number #%d was %d\n", i+1, integers[i]);
}

free_the_memory(int *ptr)
{
    free(ptr);
}

main()
{
    int     *integers = allocate_the_memory();

    use_the_memory(integers);
    free_the_memory(integers);

    fflush(stdin);
    getchar();
}






