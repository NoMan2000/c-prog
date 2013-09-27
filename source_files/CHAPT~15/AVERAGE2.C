/*
 *      average2.c
 *
 *      Program to demonstrate I/O to text files
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>

#define FNAME   "c:\\test123.txt"

static FILE    *fptr;

/*
 *  pause()
 *
 *  Ask the user to press ENTER
 *  This function is used in conjunction with atexit()
 */
void pause()
{
    printf("\nProgram ended, Press ENTER: ");
    fflush(stdin);
    getchar();
}

void close_the_file()
{
    close(fptr);
}

main()
{
    char    buffer[300];
    int     count = 0;

    atexit(pause);

    /*
     *  First, open the text file for reading
     */
    fptr = fopen(FNAME, "r");
    if (fptr == NULL)
    {
        perror("Could not open " FNAME);
        exit(1);
    }
    atexit(close_the_file);

    printf("The lines in %s are as follows:\n", FNAME);
    puts("=======================================================");

    /*
     *  Read all the lines from the file
     */
    while (fgets(buffer, sizeof buffer, fptr) != NULL)
    {
        printf("%3d: ", ++count);
        fputs(buffer, stdout);
    }

    puts("=======================================================");
    printf("\nThere were %d lines in the file\n", count);

    return 0;
}

