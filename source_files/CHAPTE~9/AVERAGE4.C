/*
 *      average4.c
 *
 *      Program to demonstrate the use of function prototypes
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

float average3(int n1, int n2, int n3);

input(int sequence)
{
    int     num;
    char    position[10];

    switch (sequence)
    {
    case 1:  strcpy(position, "first");   break;
    case 2:  strcpy(position, "second");  break;
    case 3:  strcpy(position, "third");   break;
    }

    printf("Please enter the %s number:  ", position);
    scanf("%d", &num);

    printf("The average of 4, 3 and 5 is %f\n", average3(4, 3, 5));

    return num;
}

float average3(int n1, int n2, int n3)
{
    return (float)(n1 + n2 + n3) / 3;
}

output(float a)
{
    printf("The average is %f\n", a);
}

main()
{
    int     num1, num2, num3;
    float   ave;

    num1 = input(1);
    num2 = input(2);
    num3 = input(3);

    ave = average3(num1, num2, num3);

    output(ave);

    fflush(stdin);
    getchar();
}

