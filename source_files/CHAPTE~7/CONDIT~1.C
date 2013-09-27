/*
 *      conditional.c
 *
 *      Program to demonstrate the conditional operator  (? :)
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     num1, num2;
    int     answer;

    printf("Enter the first number:  ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    answer = num2 == 0 ? -1 : num1 / num2;

    printf("%d divided by %d is %s\n",
         num1, num2,
         answer == -1 ? "undefined" : answer % 2 == 0 ? "even" : "odd");

    fflush(stdin);
    getchar();
}

