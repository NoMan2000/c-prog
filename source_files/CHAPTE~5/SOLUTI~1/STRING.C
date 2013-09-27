/*
 *      string.c
 *
 *      Program to solve Chapter 6 exercise 1 on strings
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    char    first[21];
    char    sur[21];
    char    buffer[42];
    int     i, j;

    printf("Please enter your first name: ");
    fflush(stdin);
    scanf("%[^\n]", first);
    printf("Please enter your last name:  ");
    fflush(stdin);
    scanf("%[^\n]", sur);

    /*
     *  First, copy the first name into the buffer, a la strcpy()
     */
    for (i = 0; first[i] != '\0'; i = i + 1)
        buffer[i] = first[i];

    /*
     *  Add the space
     */
    buffer[i] = ' ';
    i = i + 1;          /* don't forget to adjust the counter */

    /*
     *  Next, concatentate the surname onto the buffer, a la strcat()
     *  Notice that the for loop has TWO increments
     */
    for (j = 0; sur[j] != '\0'; j = j + 1, i = i + 1)
        buffer[i] = sur[j];
    buffer[i] = '\0';       /* don't forget to terminate the string */

    printf("The full name is >>%s<<\n", buffer);

    fflush(stdin);
    getchar();
}

