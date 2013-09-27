/*
 *      ascii2.c
 *
 *      Program to complete exercise 1, chapter 7
 *      display the ASCII character set
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     i;      /* never use a char for this - do you know why? */

    puts("The ASCII Character Set:");
    for (i = 0; i < 256; i = i + 1)
    {
        /*
         *  ensure that special characters are not printed
         */
        switch (i)
        {
        case '\n':  /* newline */
        case '\r':  /* carriage return */
        case '\t':  /* tab */
        case '\f':  /* formfeed */
        case '\b':  /* backspace */
        case '\v':  /* vertical tab */
        case 26:    /* ?? */
        case 27:    /* ?? */
            fputs("  ", stdout);
            break;
        default:
            printf("%2c ", i);
        }

        /*
         *  put a newline every 16 characters
         */
        if ((i+1) % 16 == 0)
            puts("");
    }

    fflush(stdin);
    getchar();
}

