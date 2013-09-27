/*
 *      qsort.c
 *
 *      Program to demonstrate the use of function pointers
 *      This program uses the library function qsort():
 *
 *  void qsort(void *array, int count, int size,
 *            int (*comp_func)(const void *, const void *))
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

int compare_ages(const void *v1, const void *v2)
{
    /*
     *  Create two temp pointers for convenience,
     *  to ensure that the void pointers are interpreted correctly
     */
    const emp     *e1 = v1;
    const emp     *e2 = v2;

    return e1->age - e2->age;
/* Note: could have been written: return ((emp *)v1)->age - ((emp *)v2)->age; */
}

int compare_names(const void *v1, const void *v2)
{
    /*
     *  Create two temp pointers for convenience,
     *  to ensure that the void pointers are interpreted correctly
     */
    const emp     *e1 = v1;
    const emp     *e2 = v2;

    return strcmp(e1->name, e2->name);
}

static void goodbye()
{
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

main()
{
    emp     emps[] =
    {
        {"Bob",  "123 Hope St",   45, 45000.00},
        {"Tony", "124 Hope St",   99, 46000.00},
        {"Mary", "76 Banana Ave", 12, 20000.00},
        {"Sue",  "1000 Road Rd",  45, 90000.00},
        {"Fred", "32 Nowhere Rd", 51, 49000.00}
    };
    int     i;

    atexit(goodbye);

    qsort(emps, 5, sizeof emps[0], compare_ages);

    for (i = 0; i < 5; i++)
        printf("%-10s is aged %d\n", emps[i].name, emps[i].age);

    qsort(emps, 5, sizeof emps[0], compare_names);

    for (i = 0; i < 5; i++)
        printf("%-10s\n", emps[i].name);
}

