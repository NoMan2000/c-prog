Figure 7.3  Program to Print Part of the Collating Sequence
/*
 * Prints part of the collating sequence
 */
 
#include <stdio.h>

#define START_CHAR ' '
#define END_CHAR   'Z'

int
main(void)
{
        int char_code; /* numeric code of each character printed */

        for  (char_code = (int)START_CHAR;
              char_code <= (int)END_CHAR;
              char_code = char_code + 1)
            printf("%c", (char)char_code);
        printf("\n");

        return (0);
}

 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ