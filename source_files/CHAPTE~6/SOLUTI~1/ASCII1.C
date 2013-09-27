/*
 *      ascii1.c
 *
 *      Program to complete exercise 1, chapter 7
 *      display a string's ASCII values
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    name[22];
    int     i;

    fputs("Please enter your full name (20 chars max): ", stdout);
    fgets(name, 22, stdin);
    fflush(stdin);

    /*
     *  Remove the newline (if there is one)
     */
    name[strlen(name)-1] = '\0';

    for (i = 0; name[i] != '\0'; i = i + 1)
        printf("%d ", name[i]);
    puts("");     /* put a newline on the end (puts does this automatically) */

    fflush(stdin);
    getchar();
}

