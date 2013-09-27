/*
 *  age2.c
 *
 *  Demonstrate the use of the "if...else" statement
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
    else if (age < magic_age)
        printf("You are only young!\n");
    else
        printf("You are the perfect age!!!!\n");

    if (age == 1)
        printf("Congratulations on making it though your first year\n");
    else if (age == 18)
        printf("Now you can vote!\n");
    else if (age == 21)
        printf("You have come of age!\n");
    else if (age == 40)
        printf("Life begins at forty!\n");
    else if (age == 65)
        printf("Now you can retire!\n");
    else if (age == 100)
        printf("Wow! A Century!");
    else
        printf("Your age is nothing special.  Sorry.\n");

    fflush(stdin);
    getchar();
}
