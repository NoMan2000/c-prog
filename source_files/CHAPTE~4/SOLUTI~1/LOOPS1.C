/*
 *      loops1.c
 *
 *      Program to solve the loops exercise(s) from chapter 5
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
 
main()
{
	long	number;

	for (number = 1; number <= 100; number = number + 1)
		printf("%i\n", number);

    fflush(stdin);
    getchar();
}
