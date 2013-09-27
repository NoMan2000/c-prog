/*
 *      input.c
 *
 *      Data input functions for the CD database project
 *      This is the Course Project for the C Programming Course
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#undef __STRICT_ANSI__      /* needed because I have a compiler bug */
#include <string.h>
#include "database.h"

/*
 *  The absolute maximum sized string that our program can handle
 */
#define MAX     200

/*
 *  enter()
 *
 *  Give the user a piece of information and ask them to press ENTER
 */
void enter(char prompt[])
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
 *  max = size of "answer" including NULL terminating character
 *  Note:  The answer parameter is MODIFIED by the function
 */
void read_string(char prompt[], char answer[], int max)
{
	fputs(prompt, stdout);
	fflush(stdin);
	fgets(answer, max, stdin);

    trim_newline(answer);
}

/*
 *  read_dyn_string()
 *
 *  Ask the user a question and prompt for a string answer
 *  The string is dynamically allocated (and so should be freed)
 *  The absolute maximum size that a string can ever be is given by
 *  the #define MAX
 */
char *read_dyn_string(char prompt[])
{
    char    buffer[MAX];

	fputs(prompt, stdout);
	fflush(stdin);
	fgets(buffer, sizeof buffer, stdin);

    trim_newline(buffer);

    return strdup(buffer);
}

/*
 *  read_cd()
 *
 *  Read in from the keyboard the details of one CD
 */
void read_cd(cd_t *cd)
{
	read_string("Title? ", cd->title, sizeof cd->title);
#ifndef NOARTIST
	read_string("Artist? ", cd->artist, sizeof cd->artist);
#endif
	cd->tracks = read_int("Number of tracks? ");
	cd->album = yesno("Is the CD an Album");
	cd->price = read_float("Retail price (e.g. 4.65)? ");
}

