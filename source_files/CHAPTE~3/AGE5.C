/*
 *  age5.c
 *
 *  Demonstrate the concept of boolean expressions
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     age;
    int     magic_age = 80;
    int     very_old;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);

    very_old = age >= 80;

    if (very_old)
        printf("My, you are very old!\n");
    printf("very_old = %d\n", very_old);

    fflush(stdin);
    getchar();
}
