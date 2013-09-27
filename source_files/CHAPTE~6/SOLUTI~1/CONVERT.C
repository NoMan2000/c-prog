/*
 *      convert.c
 *
 *      Program to complete exercise 1, chapter 7
 *      Convert a name to UPPERCASE and Title Case
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    name[22];
    int     i;
    int     lastblank;      /* boolean  - "The last char was a space" */

    fputs("Please enter your full name (20 chars max): ", stdout);
    fgets(name, 22, stdin);
    fflush(stdin);

    /*
     *  Remove the newline (if there is one)
     */
    name[strlen(name)-1] = '\0';

    /*
     *  First, convert to uppercase
     */
    for (i = 0; name[i] != '\0'; i = i + 1)
        name[i] = toupper(name[i]);

    /*
     *  Show the results
     */
    puts(name);

    /*
     *  Next, Title Case
     *  First, initialise the blank flag such that the first char will be
     *  converted
     */
    lastblank = 1;
    for (i = 0; name[i] != '\0'; i = i + 1)
    {
        /*
         *  Take note of every time we see a blank
         */
        if (isspace(name[i]))
        {
            lastblank = 1;
            continue;
        }

        /*
         *  This must not be a blank - check the last char
         */
        if (lastblank)
            name[i] = toupper(name[i]);
        else
            name[i] = tolower(name[i]);
        lastblank = 0;      /* This is definitely not a blank */
    }

    /*
     *  Show the results
     */
    puts(name);

    fflush(stdin);
    getchar();
}

