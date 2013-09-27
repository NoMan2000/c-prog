/*
 *      file.c
 *
 *      File input and output functions for the CD database project
 *		This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

/*
 *  file_exists()
 *
 *  Boolean - return 1 if file exists (attempts to open it for reading)
 *  If 0 is returned, errno will be set
 *  There is a better way of doing this - using "stat()"
 */
int file_exists(char *fname)
{
    FILE    *fptr;

    fptr = fopen(fname, "rb");
    if (fptr == NULL)
        return 0;
    fclose(fptr);
    return 1;
}

/*
 *  save_file()
 *
 *  Write "count" CDs to "fname" (appending to the end of the file
 *  if "append" is set to 1)
 *  Returns -1 if any error (errno will be set), or 0 for success
 */
int save_file(char *fname, cd_t **cds, int count, int append)
{
    FILE    *fptr;
    int     i;

    /*
     *  First, open the text file for writing
     */
    fptr = fopen(fname, append ? "ab" : "wb");
    if (fptr == NULL)
        return -1;

    /*
     *  Write all the records to the file
     */
    for (i = 0; i < count; i++)
        if (fwrite(cds[i], sizeof *(cds[i]), 1, fptr) != 1)
        {
            fclose(fptr);
            return -1;   
        }

    fclose(fptr);
    return 0;
}

/*
 *  open_file()
 *
 *  Read CD records from the specified file.
 *  Dynamically allocates memory enough to hold the records (must be freed).
 *  Returns a pointer to the memory, and sets "num" to be how many were read.
 *  Sets num to -1 and returns NULL if an error occurred
 */
int open_file(cd_t **new_cds, char *fname, int *num)
{
    FILE    *fptr;
    cd_t    cd;         /* buffer to hold each read */

    /*
     *  Open the file
     */
    fptr = fopen(fname, "rb");
    if (fptr == NULL)
        return -1;

    *num = 0;

    /*
     *  While we can successfully can read 1 CD from the file....
     */
    while (fread(&cd, sizeof cd, 1, fptr) == 1)
    {
        /*
         *  allocate the next element of the array
         */
        new_cds[*num] = allocate_one_cd();
        *(new_cds[*num]) = cd;         /* structure copy */
        (*num)++;                   /* note the need for brackets */
    }
    fclose(fptr);

    return 0;
}
