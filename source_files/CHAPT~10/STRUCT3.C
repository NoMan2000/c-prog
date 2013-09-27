/*
 *      struct3.c
 *
 *      Program to demonstrate the use of typedefs
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

emp read_emp()
{
    emp  e;

    printf("Please enter the age: ");
    scanf("%d", &e.age);

    return e;
}

print_emp(emp e)
{
    printf("Age is %d\n", e.age);
}

main()
{
    emp    emp1, emp2;

    emp1 = read_emp();
    emp2 = emp1;
    print_emp(emp2);

    fflush(stdin);
    getchar();
}

