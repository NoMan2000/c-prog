/*
 *  age3.c
 *
 *  Demonstrate the use of the "switch" statement
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int age;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);

    switch (age)
    {
    case 1:
    case 2:
    case 3:
        printf("Congratulations on making it though your first year\n");
        break;
    case 18:
        printf("Now you can vote!\n");
        break;
    case 21:
        printf("You have come of age!\n");
        break;
    case 40:
        printf("Life begins at forty!\n");
        break;
    case 65:
        printf("Now you can retire!\n");
        break;
    case 100:
        printf("Wow! A Century!");
        break;
    default:
        printf("Your age is nothing special.  Sorry.\n");
    }

    fflush(stdin);
    getchar();
}
