/*
 *      agesoln.c
 *
 *      Program to solve exercise 2 from chapter 8
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

    strcmp(name, "Bruce") == 0 && (age < 13 || age > 19) ?
                        printf("You are The Chosen One!\n") :
                        printf("You're NOT special\n");

    /* OR */

    printf(strcmp(name, "Bruce") == 0 && (age < 13 || age > 19) ?
                        "You are The Chosen One!\n" :
                        "You're NOT special\n");

    fflush(stdin);
    getchar();
}

