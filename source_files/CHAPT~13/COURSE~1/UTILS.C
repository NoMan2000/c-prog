/*
 *      utils.c
 *
 *      Miscellaneous helpful functions for the CD database project
 *		This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include "database.h"       /* required only for prototypes */

/*
 *  trim_newline()
 *
 *  Remove the newline character from a string (if there is one)
 *  It is assumed that if there is a newline character on the string,
 *  it will be the last character in the string (except for the NULL)
 */
trim_newline(char string[])
{
    if (string[strlen(string)-1] = '\n')
        string[strlen(string)-1] = '\0';
}

