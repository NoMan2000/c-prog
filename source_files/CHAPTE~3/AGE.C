/*
 *  age.c
 *
 *  Demonstrate the use of the basic "if" statement
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int age;
    int magic_age = 40;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);

    if (age > magic_age)
    {
        printf("My, you are very old!\n");
        printf("You are %d years older than %d\n", age - magic_age,
                                    magic_age);
    }

    fflush(stdin);
    getchar();
}
