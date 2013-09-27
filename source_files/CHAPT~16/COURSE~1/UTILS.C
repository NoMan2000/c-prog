/*
 *      utils.c
 *
 *      Miscellaneous helpful functions for the CD database project
 *		This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdlib.h>
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
 *  increase_array()
 *
 *  gracefully increase the size of a dynamically-allocated
 *  array of CDs by the number in "increase"
 *  if oldarr == NULL, then count is assumed to be 0, and v.v.
 */
cd_t *increase_array(cd_t *oldarr, int oldcount, int increase)
{
    cd_t    *newarr;

    /*
     *  Allocate memory for the next CD
     */
    if (oldcount == 0)
        newarr = malloc(increase * sizeof(cd_t));
    else
        newarr = realloc(oldarr, (oldcount+increase) * sizeof(cd_t));
    if (newarr == NULL)
    {
        printf("This program is out of memory - Exiting\n");
        exit(1);
    }

    return newarr;
}

