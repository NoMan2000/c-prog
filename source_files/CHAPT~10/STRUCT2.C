/*
 *      struct2.c
 *
 *      Program to demonstrate the use of structures with functions
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

struct employee read_emp()
{
    struct employee  emp;

    printf("Please enter the age: ");
    scanf("%d", &emp.age);

    return emp;
}

print_emp(struct employee emp)
{
    printf("Age is %d\n", emp.age);
}

main()
{
    struct employee     emp1, emp2;

    emp1 = read_emp();
    emp2 = emp1;
    print_emp(emp2);

    fflush(stdin);
    getchar();
}

