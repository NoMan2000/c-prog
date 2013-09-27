/*
 *      main.c
 *
 *      The main function for the CD database
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include "database.h"

main()
{
    cd_t    cds[NO_CDS];
    int     count = 0;           /* how many CDs are being tracked */
    int     i;                   /* loop counter */

    puts("Welcome to the CD database.");
    printf("You can store a maximum of %d CDs.\n",
                     sizeof cds / sizeof cds);

    /*
     *  Loop until they no longer wish to enter any more CDs
     */
    for (;;)        /* forever loops are convenient for this sort of thing */
	{
        /*
         *  Ask them if they want to enter another CD
         */
        if (!yesno("\nHave you any more CDs to enter"))
            break;

		printf("\nPlease enter the details of CD %d...\n\n", count+1);

		/*
		 *  Read all the CD details
		 */
        cds[count] = read_cd();

        /*
         *  Check if we have filled up the array
         */
        if (++count == NO_CDS) /* note the increment happens before the test */
        {
            enter("You have reached the limits of this program\n"
                    "Press ENTER to continue: ");
            break;
        }
    }

    /*
	 *  Output the CD details
	 */
    for (i = 0; i < count; i++)
    {
        printf("\nThe details of CD %d are:\n", i+1);
        print_cd(cds[i]);

        if (i < count - 1)    /* only do this if there are more CDs to see */
            enter("\nPress ENTER to see the next set of details: ");
	}

    /*
     *  Exit the program
     */
    enter("\nPress ENTER to exit the program: ");
}

