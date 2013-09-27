/*
 *      average2.c
 *
 *      Program to demonstrate the use of function parameters
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

float   ave;

average3(int n1, int n2, int n3)
{
    ave = (float)(n1 + n2 + n3) / 3;
}

main()
{
    int     num1, num2, num3;

    printf("Please enter the first number:  ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    printf("Please enter the third number:  ");
    scanf("%d", &num3);

    average3(num1, num2, num3);

    printf("The average is %f\n", ave);

    fflush(stdin);
    getchar();
}

