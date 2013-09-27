/*
 *      database.c
 *
 *      Program to maintain a database of CDs for a record store.
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include "database.h"

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

/*
 *  enter()
 *
 *  Give the user a piece of information and ask them to press ENTER
 */
enter(char prompt[])
{
    fputs(prompt, stdout);
    fflush(stdin);
    getchar();
}

/*
 *  yesno()
 *
 *  Ask the user a question and prompt for a Y or N (or y or n) answer
 *  No other answer will be acceptable
 *  If y/Y is given the function returns 1.  n/N gives 0
 */
int yesno(char prompt[])    /* prompt should NOT include a question mark */
{
    char    answer;

    /*
     *  loop until a correct answer is given
     */
    for (;;)
	{
		fputs(prompt, stdout);          /* display the question */
        fputs(" (Y/N)? ", stdout);      /* add a helpful prompt */
		fflush(stdin);
		scanf("%c", &answer);

        /*
         *  process the answer
         */
        answer = toupper(answer);       /* convert to uppercase */
		if (answer == 'Y')
            return 1;
        if (answer == 'N')      /* notice no "else" is required */
			return 0;
        printf("Error - only 'y/Y' or 'n/N' are allowed\n");
	}
}

/*
 *  read_int()
 *
 *  Ask the user a question and prompt for an integer answer
 */
int read_int(char prompt[])
{
    int     answer;

	fputs(prompt, stdout);
	fflush(stdin);
	scanf("%d", &answer);

    return answer;
}

/*
 *  read_float()
 *
 *  Ask the user a question and prompt for a float answer
 */
float read_float(char prompt[])
{
    float     answer;

	fputs(prompt, stdout);
	fflush(stdin);
	scanf("%f", &answer);

    return answer;
}

/*
 *  read_string()
 *
 *  Ask the user a question and prompt for a string answer
 *  MAX = size of "answer" including NULL terminating character
 *  Note:  The answer parameter is MODIFIED by the function
 */
read_string(char prompt[], char answer[], int MAX)
{
	fputs(prompt, stdout);
	fflush(stdin);
	fgets(answer, MAX, stdin);

    trim_newline(answer);
}

/*
 *  read_cd()
 *
 *  Read in from the keyboard the details of one CD
 */
cd_t read_cd()
{
    cd_t    cd;

	read_string("Title? ", cd.title, sizeof cd.title);
#ifndef NOARTIST
	read_string("Artist? ", cd.artist, sizeof cd.artist);
#endif
	cd.tracks = read_int("Number of tracks? ");
	cd.album = yesno("Is the CD an Album");
	cd.price = read_float("Retail price (e.g. 4.65)? ");

    return cd;
}

/*
 *  print_cd()
 *
 *  Display (using printf) the details of one CD
 */
print_cd(cd_t cd)
{
    puts("========================");
    printf("Title: %s\n", cd.title);
#ifndef NOARTIST
	printf("Artist: %s\n", cd.artist);
#endif
	printf("Number of tracks: %d\n", cd.tracks);
	puts(cd.album ? "Album" : "Single");
	printf("Price: %.2f\n", cd.price);
    puts("========================");
}

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

