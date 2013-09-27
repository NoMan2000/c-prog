/*
 *      loops3.c
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
	long	number;		/* each number to try */
	long	divisor;	/* the number we try dividing into the above */

	printf("Please enter a number to start at: ");
	scanf("%ld", &start);
 
	printf("Please enter the number of numbers: ");
	scanf("%ld", &count);

	for (number = start; number < start + count; number = number + 1)
	{
		/*
		 * now find the divisors (evenly dividing numbers), by trying all
		 * the numbers from 1 up to the number
		 */
		printf("The divisors of %i are: ", number );

		for (divisor = 1; divisor <= number; divisor = divisor + 1)
        {
			/*
			 *  if this divisor divides evenly into the number...
			 */
			if (number % divisor == 0)
        		printf("%i ", divisor);
		}

		printf("\n");
	}

    fflush(stdin);
    getchar();
}
