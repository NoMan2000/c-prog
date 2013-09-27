/*
 *      strlen.c
 *
 *      Program to demonstrate the use of function parameters being passed
 *      into functions
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int     length;

strlength(char str[])
{
    for (length = 0; str[length] != '\0'; length++)
        ;       /* do nothing loop */
}

main()
{
    char    string[100];

    printf("Please enter your first name: ");
    scanf("%[^\n]", string);

    strlength(string);

    printf("Length of >>%s<< is %d\n", string, length);

    fflush(stdin);
    getchar();
}

