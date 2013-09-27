/*
 *      database.c
 *
 *      Program to maintain a database of CDs for a record store.
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    title[100][61];
    char    artist[100][61];
    int     tracks[100];         /* number of tracks on the CD */
    char    type;                /* used to read in album/single info */
    int     album[100];          /* boolean - is the CD an ALBUM? */
    float   price[100];
    int     count = 0;           /* how many CDs are being tracked */
    int     i;                   /* loop counter */

    printf("Welcome to the CD database.\n");
    printf("You can store a maximum of 100 CDs.\n");

    /*
     *  Loop until they no longer wish to enter any more CDs
     */
    for (;;)        /* forever loops are convenient for this sort of thing */
	{
        /*
         *  Ask them if they want to enter another CD
         *  Any answer other than y or Y will be treated as a NO
         */
        printf("\nHave you any more CDs to enter (y/n)? ");
        fflush(stdin);
        scanf("%c", &type);
        if (type != 'y' && type != 'Y')
            break;

        printf("\n");       /* for neat output */

		/*
		 *  First, the title
		 */
		printf("Please enter the details of CD %d...\n\n", count+1);
		printf("Title? ");
        fflush(stdin);
		scanf("%[^\n]", title[count]);

		/*
		 *  Next, the artist
		 */
		printf("Artist? ");
		fflush(stdin);
		scanf("%[^\n]", artist[count]);

		/*
		 *  Next, the number of tracks
		 */
		printf("Number of tracks? ");
		fflush(stdin);
		scanf("%d", &tracks[count]);

		/*
		 *  Next, Album/single
		 */
		for (;;)
		{
			printf("Album or single (a for album, s for single)? ");
			fflush(stdin);
			scanf("%c", &type);
			if (type == 'a' || type == 's')
				break;
			printf("Error - only 'a' or 's' are allowed\n");
		}
		album[count] = type == 'a';    /* if we get here it must be 'a' or 's' */

		/*
		 *  Next, the price
		 */
		printf("Retail price (e.g. 4.65)? ");
		fflush(stdin);
		scanf("%f", &price[count]);

        count = count + 1;

        /*
         *  Check if we have filled up the array
         */
        if (count == 100)
        {
            printf("You have reached the limits of this program\n\n");
            break;
        }
    }

    /*
	 *  Output the CD details
	 */
    for (i = 0; i < count; i = i + 1)
    {
		printf("\nThe details of CD %d are:\n", i+1);
		printf("============================\n");
		printf("Title: %s\n", title[i]);
		printf("Artist: %s\n", artist[i]);
		printf("Number of tracks: %d\n", tracks[i]);
		if (album[i])
			printf("Album\n");
		else
			printf("Single\n");
		printf("Price: %.2f\n", price[i]);
		printf("============================\n");

        if (i < count - 1)    /* only do this if there are more CDs to see */
        {
            /*
             *  A user-friendly way to progress to the next CD
             */
            printf("\nPress ENTER to see the next set of details: ");
            fflush(stdin);
            getchar();
        }
	}

    /*
     *  A user-friendly exit of the program
     */
    printf("\nPress ENTER to exit the program: ");
    fflush(stdin);
    getchar();
}

