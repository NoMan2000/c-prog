/*
 *      ptr2ptr.c
 *
 *      Program to demonstrate the use of pointers to pointers
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct employee
{
    char    name[31];
    char    address[101];
    int     age;
    float   salary;
};

typedef struct employee   emp;

/*
 *  oldest()
 *
 *  Function to find the oldest of 2 emp structures
 *  the pointer to a pointer to an emp "e_ptr" has
 *  its contents (a pointer to an emp) assigned to the appropriate one
 */
static void oldest(emp *emps, emp **e_ptr)
{
    if (emps[0].age > emps[1].age)
        *e_ptr = emps + 0;         /* note:  *e_ptr */
    else
        *e_ptr = &(emps[1]);
}

static void goodbye()
{
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

main()
{
    emp     emps[2] =
    {
        {"Bob",  "123 Hope St",   45, 45000.00},
        {"Fred", "32 Nowhere Rd", 51, 49000.00}
    };
    emp     *elder;

    atexit(goodbye);

    oldest(emps, &elder);

    printf("The oldest employee is aged %d\n", elder->age);
}

