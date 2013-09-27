/*
 *      employee.c
 *
 *      Program to demonstrate I/O to binary files
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>       /* for time() and ctime() */

#define FNAME   "c:\\emp.dat"

struct employee
{
    char    name[31];
    char    address[101];
    int     age;
    float   salary;
};

typedef struct employee   emp;

static void read_emp(emp *e)
{
    printf("Please enter the name: ");
    fflush(stdin);
    scanf("%[^\n]", &e->name);

    printf("Please enter the address (on one line): ");
    fflush(stdin);
    scanf("%[^\n]", &e->address);

    printf("Please enter the age: ");
    fflush(stdin);
    scanf("%d", &e->age);

    printf("Please enter the salary: ");
    fflush(stdin);
    scanf("%f", &e->salary);
}

static void print_emp(emp *e)
{
    printf("Name is %s\n", e->name);
    printf("Address is %s\n", e->address);
    printf("Age is %d\n", e->age);
    printf("Salary is $%.2f\n", e->salary);
}

/*
 *  pause()
 *
 *  Ask the user to press ENTER
 *  This function is used in conjunction with atexit()
 */
static void pause()
{
    printf("\nProgram ended, Press ENTER: ");
    fflush(stdin);
    getchar();
}

main()
{
    FILE    *fptr;
    emp     e;
    int     count;
    int     i;

    atexit(pause);

    /*
     *  First, open the text file for writing
     *  and write out the header info to it
     */
    fptr = fopen(FNAME, "wb");
    if (fptr == NULL)
    {
        perror("Couldn't open(w) the file " FNAME);
        exit(1);
    }

    /*
     *  Determine how many employee details to be processed
     */
    printf("How many employees do you want to enter: ");
    scanf("%d", &count);

    /*
     *  Read all the details and write them to the file
     */
    for (i = 0; i < count; i++)
    {
        printf("Please enter details for employee %d:\n", i+1);
        read_emp(&e);

        /*
         *  Write the details out to the file
         */
        if (fwrite(&e, sizeof e, 1, fptr) < 1)
        {
            perror("Couldn't write to the file" FNAME);
            exit(1);
        }
    }
    fclose(fptr);

    /*
     *  Next, open the file again, for READING this time
     */
    fptr = fopen(FNAME, "rb");
    if (fptr == NULL)
    {
        perror("Couldn't open(r) the file " FNAME);
        exit(1);
    }

    /*
     *  While we can successfully can read from the file, output the results
     */
    for (i = 0; fread(&e, sizeof e, 1, fptr) == 1; i++)
    {
        puts("===========================");
        printf("Details of employee %d are:\n", i+1);
        print_emp(&e);
    }

    /*
     *  A final message, then close the file
     */
    printf("\n%d records were written and read\n", i);
    fclose(fptr);

    return 0;
}

