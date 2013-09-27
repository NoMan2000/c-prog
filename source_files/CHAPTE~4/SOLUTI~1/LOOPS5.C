/*
 *      loops5.c
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
    long    divisors;   /* the number of divisors found for each number */
	long	max;		/* the last divisor we need to test */
 
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

		divisors = 0;
		max = number;
		for (divisor = 1; divisor < max; divisor = divisor + 1)
        {
			/*
			 *  if this divisor divides evenly into the number
			 */
			if (number % divisor == 0)
            {
        		printf("%i ", divisor);

                /*
                 *  print out the other divisor too, but check that it's
                 *  not the same as the first one
                 */
                if (divisor != number / divisor)
                    printf("%i ", number / divisor);
    			divisors = divisors + 1;     /* one more PAIR of divisors */
            }

			/*
			 * now the clever bit:
			 * It will now not be necessary to check any numbers above the value
			 * number/divisor, so reduce our maximum to this new value
			 */
			if (number / divisor < max)
				max = number / divisor;
		}

		/*
		 *  the number is a prime if it has only one (pair of) divisors
		 */
		if (divisors == 1)
			printf("*");

		printf("\n");
	}

    fflush(stdin);
    getchar();
}
