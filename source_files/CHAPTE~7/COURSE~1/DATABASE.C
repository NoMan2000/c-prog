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

    puts("Welcome to the CD database.");
    printf("You can store a maximum of %d CDs.\n",
                     sizeof price / sizeof price[0]);

    /*
     *  Loop until they no longer wish to enter any more CDs
     */
    for (;;)        /* forever loops are convenient for this sort of thing */
	{
        /*
         *  Ask them if they want to enter another CD
         *  Any answer other than y or Y will be treated as a NO
         */
        fputs("\nHave you any more CDs to enter (y/n)? ", stdout);
        fflush(stdin);
        scanf("%c", &type);
        if (toupper(type) != 'Y')
            break;

        puts("");       /* newline - for neat output */

		/*
		 *  First, the title
		 */
		printf("Please enter the details of CD %d...\n\n", count+1);
		fputs("Title? ", stdout);
        fflush(stdin);
		fgets(title[count], sizeof title[count], stdin);
        title[count][strlen(title[count])-1] = '\0';

		/*
		 *  Next, the artist
		 */
		fputs("Artist? ", stdout);
		fflush(stdin);
		fgets(artist[count], sizeof artist[count], stdin);
        artist[count][strlen(artist[count])-1] = '\0';

		/*
		 *  Next, the number of tracks
		 */
		fputs("Number of tracks? ", stdout);
		fflush(stdin);
		scanf("%d", &tracks[count]);

		/*
		 *  Next, Album/single
		 */
		for (;;)
		{
			fputs("Album or single (a for album, s for single)? ", stdout);
			fflush(stdin);
			scanf("%c", &type);
            type = toupper(type);
			if (type == 'A' || type == 'S')
				break;
			printf("Error - only 'a/A' or 's/S' are allowed\n");
		}
		album[count] = type == 'A';    /* if we get here it must be 'a' or 's' */

		/*
		 *  Next, the price
		 */
		fputs("Retail price (e.g. 4.65)? ", stdout);
		fflush(stdin);
		scanf("%f", &price[count]);

        /*
         *  Check if we have filled up the array
         */
        if (++count == 100)   /* note the increment happens before the test */
        {
            puts("You have reached the limits of this program\n");
            break;
        }
    }

    /*
	 *  Output the CD details
	 */
    for (i = 0; i < count; i++)
    {
		printf("\nThe details of CD %d are:\n", i+1);
        puts("========================");
		printf("Title: %s\n", title[i]);
		printf("Artist: %s\n", artist[i]);
		printf("Number of tracks: %d\n", tracks[i]);
		puts(album[i] ? "Album" : "Single");
		printf("Price: %.2f\n", price[i]);
        puts("========================");

        if (i < count - 1)    /* only do this if there are more CDs to see */
        {
            /*
             *  A user-friendly way to progress to the next CD
             */
            fputs("\nPress ENTER to see the next set of details: ", stdout);
            fflush(stdin);
            getchar();
        }
	}

    /*
     *  A user-friendly exit of the program
     */
    fputs("\nPress ENTER to exit the program: ", stdout);
    fflush(stdin);
    getchar();
}

