//
//  Comment2.c
//
//  A program used to demonstrate the use of comments
//  by showing how to calculate the area of a circle
//
//  by Mark Virtue, 2001.
//
#include <stdio.h>

main()
{
    double  pi = 3.1415926536;  // we need a lot of precision
    int     radius;
    double  area;

    printf("Please enter the radius: ");
    scanf("%d", &radius);

    //
    //  The area of a circle is:
    //  PI times the radius squared
    //
    area = pi * radius * radius;
    printf("The area of the circle would be %f\n", area);

    fflush(stdin);
    getchar();
}
