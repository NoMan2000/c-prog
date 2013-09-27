/*
 *  age4.c
 *
 *  Demonstrate the use of the various relational operators
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     age;
    char    name[41];

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);

    if (age <= 19)
    {
        if (age >= 13)
            printf("You are a teenager\n");
        else
            printf("You are just a kid\n");
    }
    else
        printf("My, you are very old!\n");

    printf("Please enter your name: ");
    scanf("%s", name);

    if (strcmp(name, "Bruce") != 0)
        printf("You are not called Bruce.  Do you mind if I call you Bruce?\n");

    fflush(stdin);
    getchar();
}
