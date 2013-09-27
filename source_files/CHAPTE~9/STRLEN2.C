/*
 *      strlen2.c
 *
 *      Program to demonstrate the use of function parameters being passed
 *      into functions
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int strlength(char str[])
{
    int     i;

    for (i = 0; str[i] != '\0'; i++)
        ;       /* do nothing loop */
    return i;
}

main()
{
    char    string[100];
    int     length;

    printf("Please enter your first name: ");
    scanf("%[^\n]", string);

    length = strlength(string);

    printf("Length of >>%s<< is %d\n", string, length);

    printf("Please enter your last name: ");
    fflush(stdin);
    scanf("%[^\n]", string);

    length = strlength(string);

    printf("Length of >>%s<< is %d\n", string, length);

    fflush(stdin);
    getchar();
}

