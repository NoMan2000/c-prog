/*
 *      utils.c
 *
 *      Miscellaneous helpful functions for the CD database project
 *		This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdlib.h>
#include <stdio.h>
#include "database.h"       /* required only for prototypes */

/*
 *  trim_newline()
 *
 *  Remove the newline character from a string (if there is one)
 *  It is assumed that if there is a newline character on the string,
 *  it will be the last character in the string (except for the NULL)
 */
void trim_newline(char string[])
{
    if (string[strlen(string)-1] = '\n')
        string[strlen(string)-1] = '\0';
}

/*
 *  allocate_one_cd()
 *
 *  Set aside space for one CD from the heap
 *  This will need to be freed
 *  If memory is not available, we exit the program
 */
cd_t *allocate_one_cd()
{
    cd_t    *ptr;

    if ((ptr = malloc(sizeof *ptr)) == NULL)
    {
        fprintf(stderr, "This program is out of memory - Exiting\n");
        exit(1);
    }
    return ptr;
}

