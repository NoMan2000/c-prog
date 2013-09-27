/*
 *      string.c
 *
 *      Program to illustrate the use of gets, puts and fgets
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    name[22];
    int     len;

    fputs("Please enter your full name (20 chars max): ", stdout);
    fgets(name, 22, stdin);
    fflush(stdin);

    len = strlen(name);
    name[len-1] = '\0';

    fputs("Your full name is ", stdout);
    puts(name);

    fflush(stdin);
    getchar();
}

