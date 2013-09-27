/*
 *      and_or.c
 *
 *      Program to demonstrate the use of bit-sized & and | operators
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MARRIED     (1<<0)
#define MANAGER     (1<<1)
#define MALE        (1<<2)

struct employee
{
    char    name[31];
    char    address[101];
    int     age;
    float   salary;
    int     flags;
};

typedef struct employee   emp;

static read_emp(emp *e)
{
    char    answer;

    e->flags = 0;

    printf("Please enter the age: ");
    scanf("%d", &e->age);

    printf("Married (Y/N)? ");
    fflush(stdin);
    answer = getchar();
    if (toupper(answer) == 'Y')
        e->flags |= MARRIED;
    else
        e->flags &= ~MARRIED;
}

static void print_emp(emp *e)
{
    printf("Age is %d\n", e->age);
    puts((e->flags & MARRIED) ? "Married" : "Not married");
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

