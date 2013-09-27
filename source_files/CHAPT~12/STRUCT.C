/*
 *      struct.c
 *
 *      Program to demonstrate the use of pointers to structures
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

typedef struct employee   emp;

read_emp(emp *e)
{
    printf("Please enter the age: ");
    scanf("%d", &(e->age));
}

print_emp(emp *e)
{
    printf("Age is %d\n", e->age);
}

main()
{
    emp    emp1, emp2;

    read_emp(&emp1);
    emp2 = emp1;
    print_emp(&emp2);

    fflush(stdin);
    getchar();
}

