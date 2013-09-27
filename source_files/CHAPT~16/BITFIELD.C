/*
 *      bitfield.c
 *
 *      Program to demonstrate the use of bit-sized structure fields
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
    int     married  :1;
    int     manager  :1;
    int     male     :1;
    int     num_kids :4;        /* limit of 15 kids */
};

typedef struct employee   emp;

static read_emp(emp *e)
{
    char    answer;

    printf("Please enter the age: ");
    scanf("%d", &e->age);

    printf("Married (Y/N)? ");
    fflush(stdin);
    answer = getchar();
    e->married = toupper(answer) == 'Y';
}

static void print_emp(emp *e)
{
    printf("Age is %d\n", e->age);
    puts(e->married ? "Married" : "Not married");
}

static void goodbye()
{
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

main()
{
    emp    e;

    atexit(goodbye);

    read_emp(&e);
    print_emp(&e);
}

