/*
 *      floats.c
 *
 *      Program to solve exercise 2, chapter 15
 *      3 ways of creating 150 floats
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>     /* provides prototypes for malloc and free */
                        /* (among other things) */

#define QTY_REQD    150

main()
{
    static float   the_static_ones[QTY_REQD];
    float   the_stack_ones[QTY_REQD];
    float   *the_heap_ones;

    /*
     *  Allocate space for "count" integers
     */
    the_heap_ones = malloc(QTY_REQD * sizeof(float));
    if (the_heap_ones == NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }

    free(the_heap_ones);
}

