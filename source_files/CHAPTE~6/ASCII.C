/*
 *      ascii.c
 *
 *      Program to illustrate the concepts of the ASCII character set
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     number;
    char    ch;

    /*
     *  All these are perfectly legal
     */
    number = 97;
    number = 'a';
    number = '\x6f';        /* 111, the letter 'o' */
    ch = 'a';
    ch = 97;
    ch = '\x6f';

    printf("number is %d\n", number);
    printf("number is %c\n", number);
    printf("ch is %c\n", ch);
    printf("ch is %d\n", ch);

    fflush(stdin);
    getchar();
}

