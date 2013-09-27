/*
 *      struct.c
 *
 *      Program to demonstrate the basic use of structures
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

struct employee
{
    char    name[31];
    char    address[101];
    int     age;
    float   salary;
};

main()
{
    struct employee     emp1, emp2;

    emp1.age = 34;
    printf("Age is %d\n", emp1.age);

    emp2 = emp1;
    printf("Age 2 is %d\n", emp2.age);

    fflush(stdin);
    getchar();
}

