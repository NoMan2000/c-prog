/*
 *  printf.c
 *
 *  Demonstrate the use of the printf() function
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     x = 415;
    double  y = 3.14159;
    int     len = 7;
    char    string[30];

    strcpy(string, "Hello");/* string is the only variable not initialised */
    
    /*
     *  string formatting options
     */
    printf("123456789012345678901234567890\n");
    printf("%s<<<<\n", string);
    printf("%10s<<<<\n", string);
    printf("%-10s<<<<\n", string);
    printf("%.3s<<<<\n", string);
    printf("%.*s<<<<\n", len, string);

    /*
     *  integer formatting options
     */
    printf("123456789012345678901234567890\n");
    printf("%d<<<<\n", x);
    printf("%10d<<<<\n", x);
    printf("%010d<<<<\n", x);
    printf("%*d<<<<\n", len, x);
    printf("%-10d<<<<\n", x);
    printf("%.1d<<<<\n", x);

    /*
     *  character formatting options
     */
    printf("123456789012345678901234567890\n");
    printf("%c<<<<\n", string[0]);
    printf("%10c<<<<\n", string[0]);

    /*
     *  floating-point formatting options
     */
    printf("123456789012345678901234567890\n");
    printf("%f<<<<\n", y);
    printf("%10f<<<<\n", y);
    printf("%10.3f<<<<\n", y);
    printf("%10.8f<<<<\n", y);

    /*
     *  other features
     */
    printf("123456789012345678901234567890\n");
    printf("%%\n");

    fflush(stdin);
    getchar();
}

