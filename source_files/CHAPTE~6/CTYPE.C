/*
 *      ctype.c
 *
 *      Program to show examples of the use of isupper, toupper, etc
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <ctype.h>

main()
{
    char    ch;

    printf("Please type in a character: ");
    scanf("%c", &ch);

    if (isupper(ch))
    {
        printf("This is an uppercase character\n");
        ch = tolower(ch);
        printf("Lowercase equivalent is '%c'\n", ch);
    }
    else if (islower(ch))
        printf("This is an lowercase character\n");
    else if (isdigit(ch))
        printf("This is an digit\n");
    else if (isspace(ch))
        printf("This is an space-type char\n");

    fflush(stdin);
    getchar();
}

