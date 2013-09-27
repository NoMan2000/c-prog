/*
 *      agesoln.c
 *
 *      Program to solve exercise 2 from chapter 4
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     age;
    char    name[41];

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your name: ");
    scanf("%s", name);

    if (strcmp(name, "Bruce") == 0 && (age < 13 || age > 19))
        printf("You are The Chosen One!\n");
    else
        printf("You're NOT special\n");

    fflush(stdin);
    getchar();
}

