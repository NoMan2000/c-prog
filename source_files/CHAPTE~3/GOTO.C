/*
 *  goto.c
 *
 *  Demonstrate the use (or misuse) of the goto statement
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     age;
    char    name[41];
    int     very_old;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("You are %d years old\n", age);

    if (!(age <= 19 && age >= 13))
        goto other;
    if (age > 19 || age < 13)
        printf("You are not a teenager\n");

up:
    if (age == 10 || age == 20 || age == 30 || age > 100)
        printf("You have a special age\n");

    printf("Please enter your name: ");
    scanf("%s", name);

    if (!(strcmp(name, "Bruce") != 0 && age != 40))
        printf("You not called Bruce and are aged 40.\n");
    if (strcmp(name, "Bruce") == 0 || age == 40)
        printf("You not called Bruce and are aged 40.\n");

other:
    very_old = age > 80;

    if (!very_old)
        printf("You are not very old\n");
    if (very_old == 0)
        printf("You are not very old\n");

    if (age > 10)
        goto up;
    fflush(stdin);
    getchar();
}
