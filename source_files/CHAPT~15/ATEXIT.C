/*
 *      atexit.c
 *
 *      Program to demonstrate the use of atexit
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>

void say_goodbye()
{
    printf("Goodbye for now (press ENTER): ");
    fflush(stdin);
    getchar();
}

static void log_off_database()
{
    printf("We are now logged off the database\n");
}

static void log_onto_database()
{
    printf("We are now logged onto the database\n");
    atexit(log_off_database);
}

static void process_things()
{
    int     x;

    printf("Please enter a number: ");
    scanf("%d", &x);

    if (x > 10)
    {
        printf("That number is too big - exiting...\n");
        exit(1);
    }

    printf("No problem - continuing normally...\n");
}

main()
{
    atexit(say_goodbye);

    log_onto_database();
    process_things();

    return 0;
}

