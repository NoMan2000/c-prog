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

static FILE     *gl_fptr;       /* used to pass data to write_one_record */

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

static int  write_one_record(void *data)
{       
    return fwrite(data, sizeof(cd_t), 1, gl_fptr) == 1 ? GLIST_OK : GLIST_ERR;
}

/*
 *  save_file()
 *
 *  Write the CDs to "fname" (appending to the end of the file
 *  if "append" is set to 1)
 *  Returns -1 if any error (errno will be set), or 0 for success
 */
int save_file(char *fname, glist_t *cds, int append)
{
    int     rv;

    /*
     *  First, open the text file for writing
     */
    gl_fptr = fopen(fname, append ? "ab" : "wb");
    if (gl_fptr == NULL)
        return -1;

    /*
     *  Write all the records to the file
     */
    rv = list_do(cds, write_one_record);
    fclose(gl_fptr);
    return rv == list_count(cds) ? 0 : -1;
}

/*
 *  open_file()
 *
 *  Read CD records from the specified file into the (initialised) list
 *  Returns 0, or -1 if an error occurred
 */
int open_file(glist_t *new_cds, char *fname)
{
    FILE    *fptr;
    cd_t    cd;         /* buffer to hold each read */

    /*
     *  Open the file
     */
    fptr = fopen(fname, "rb");
    if (fptr == NULL)
        return -1;

    /*
     *  While we can successfully can read 1 CD from the file....
     */
    while (fread(&cd, sizeof cd, 1, fptr) == 1)
        if (list_add(new_cds, &cd, sizeof cd) == GLIST_ERR)
        {
            fprintf(stderr, "Out of memory - exiting\n");
            exit(1);
        }
    fclose(fptr);

    return 0;
}
