/*
 *  fullname.c
 *
 *  Solution to the name exercise from Chapter 3.
 *  Ask for a user's first name and surname as two separate questions
 *  and output the result as a concatenated string (plus the length of the
 *  name).
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    first[31];
    char    sur[31];
    char    result[62];

    /*
     *  First, get the names from the keyboard
     */
    printf("Please enter your FIRST name: ");
    scanf("%[^\n]", first);
    printf("Please enter your LAST name:  ");
    fflush(stdin);
    scanf("%[^\n]", sur);

    /*
     *  Concatenate them together into "result" with a space between
     */
    strcpy(result, first);
    strcat(result, " ");
    strcat(result, sur);

    /*
     *  Output the result
     */
    printf("Your FULL name is %s (length %d)\n", result, strlen(result));

    fflush(stdin);
    getchar();
}

