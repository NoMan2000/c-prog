/*
 *      string.c
 *
 *      Program to illustrate the makeup of a string
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    name[51];
    int     length;

    printf("Please enter your name: ");
    scanf("%s", name);

    for (length = 0; name[length] != '\0'; length = length + 1)
        ;       /* do nothing loop */

    printf("The length of >>>%s<<< is %d\n", name, length);
    fflush(stdin);
    getchar();
}

