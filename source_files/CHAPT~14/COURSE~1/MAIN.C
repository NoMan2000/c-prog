/*
 *      main.c
 *
 *      The main function for the CD database
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include "database.h"

main()
{
    cd_t    *cds;
    int     count;           /* how many CDs are being tracked */
    int     i;               /* loop counter */

    puts("Welcome to the CD database.");

    /*
     *  Ask them if they want to enter another CD
     */
    count = read_int("\nHow many CDs do you have to enter? ");

    /*
     *  Allocate memory for that number of CDs
     */
    cds = malloc(count * sizeof(cd_t));
    if (cds == NULL)
    {
        printf("This program is out of memory - Exiting\n");
        exit(1);
    }

    /*
     *  Read in all the CDs
     */
    for (i = 0; i < count; i++)
    {
		printf("\nPlease enter the details of CD %d...\n\n", i+1);
        read_cd(&cds[i]);
    }

    /*
	 *  Output the CD details
	 */
    for (i = 0; i < count; i++)
    {
        printf("\nThe details of CD %d are:\n", i+1);
        print_cd(&cds[i]);

        if (i < count - 1)    /* only do this if there are more CDs to see */
            enter("\nPress ENTER to see the next set of details: ");
	}

    /*
     *  Perform any necessary "free"ing
     */
    for (i = 0; i < count; i++)
    {
        free(cds[i].title);
#ifndef NOARTIST
        free(cds[i].artist);
#endif
	}
    free(cds);

    /*
     *  Exit the program
     */
    enter("\nPress ENTER to exit the program: ");
}

