/*
 *      average.c
 *
 *      Program to solve exercise 2, chapter 15 - averaging numbers
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>     /* provides prototypes for malloc and free */
                        /* (among other things) */

main()
{
    int     count;
    int     total = 0;
    int     i;
    int     *ptr;       /* the "array" of integers */

    /*
     *  First, determine how many integers are to be averaged
     */
    printf("How many numbers do you want to average: ");
    scanf("%d", &count);

    /*
     *  Allocate space for "count" integers
     */
    ptr = malloc(count * sizeof(int));
    if (ptr == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    for (i = 0; i < count; i++)
    {
        printf("Please enter number #%d: ", i+1);
        fflush(stdin);
        scanf("%d", &ptr[i]);

        /*
         *  Add this integer to our total
         */
        total += ptr[i];
    }

    /*
     *  We no longer need the memory, so free it
     */
    free(ptr);

    printf("The average is %f\n", (float)total / count);

    fflush(stdin);
    getchar();
}

