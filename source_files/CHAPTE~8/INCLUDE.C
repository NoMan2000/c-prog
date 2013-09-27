/*
 *      include.c
 *
 *      Program to demonstrate the use of the #include directive
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <string.h>

main()
{
    char    name[41];
    int     length;

    printf("Please enter your name: ");
    scanf("%s", name);

    length = strlen(name);
    printf("Length of >>%s<< is %d\n", name, length);

    fflush(stdin);
    getchar();
}

