/*
 *      average.c
 *
 *      Program to demonstrate the use of global variables
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

int     num1, num2, num3;
float   ave;

input()
{
    printf("Please enter the first number:  ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    printf("Please enter the third number:  ");
    scanf("%d", &num3);
}

average()
{
    ave = (float)(num1 + num2 + num3) / 3;
}

output()
{
    printf("The average is %f\n", ave);
}

main()
{
    input();
    average();
    output();

    fflush(stdin);
    getchar();
}

