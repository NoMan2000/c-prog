/*
 *      loops2.c
 *
 *      Program to solve the loops exercise(s) from chapter 5
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
 
main()
{
	long	start;		/* the first number */
	long	count;		/* the number of numbers */
	long	number;		/* each number to print */

	printf("Please enter a number to start at: ");
	scanf("%ld", &start);
 
	printf("Please enter the number of numbers: ");
	scanf("%ld", &count);

	for (number = start; number < start + count; number = number + 1)
		printf("%i\n", number);

    fflush(stdin);
    getchar();
}
