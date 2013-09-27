/*
 *      average.c
 *
 *      Program to demonstrate I/O to text files
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* for time() and ctime() */

#define FNAME   "c:\\test123.txt"

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

main()
{
    FILE    *fptr;
    int     count;
    int     number;
    int     total = 0;
    time_t  the_time;
    int     i;

    atexit(pause);

    /*
     *  First, open the text file for writing
     *  and write out the header info to it
     */
    fptr = fopen(FNAME, "w");
    if (fptr == NULL)
    {
        fprintf(stderr, "Could not open %s - %s\n",
                         FNAME, sys_errlist[errno]);
        exit(1);
    }

    /*
     *  Test to see if we can write to the file
     */
    if (fprintf(fptr, "This is the output file for the File I/O program\n\n")
                    < 0)
    {
        perror("Could not write to the file");
        fclose(fptr);
        exit(1);
    }

    /*
     *  Write the rest of the header info, including the current time
     */
    the_time = time(NULL);
    fprintf(fptr, "\t\tCreated on %s\n\n", ctime(&the_time));
    fputs("The numbers are:\n\n", fptr);

    /*
     *  Determine how many integers are to be averaged
     */
    printf("How many numbers do you want to average: ");
    scanf("%d", &count);

    /*
     *  We don't want to divide by zero if count == 0, so...
     */
    if (count == 0)
    {
        fputs("No numbers to average\n", fptr);
        fclose(fptr);
        exit(0);
    }

    /*
     *  Otherwise, read all the numbers and accumulate them
     */
    for (i = 0; i < count; i++)
    {
        printf("Please enter number #%d: ", i+1);
        fflush(stdin);
        scanf("%d", &number);

        /*
         *  Add this integer to our total
         */
        total += number;

        /*
         *  Write the number out to the file
         */
        fprintf(fptr, "%3d: %4d\n", i+1, number);
    }

    /*
     *  A final message, then close the file
     */
    fprintf(fptr, "\nThe average is %f\n", (float)total / count);
    fclose(fptr);

    return 0;
}

