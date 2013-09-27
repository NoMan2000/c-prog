/*
 * Determines the value of a collection of coins.
 */
#include <stdio.h>

int
main(void)
{
     char first, middle, last;	/* input - 3 initials     	*/
     int pennies, nickels;  /* input - count of each coin type	*/
     int dimes, quarters;   /* input - count of each coin type	*/
     int change; 	/* output - change amount    	*/
     int dollars;        	/* output - dollar amount   	*/
     int total_cents;  	/* total cents             	*/
 
     /* Get and display the customer's initials. */ 
     printf("Type in 3 initials and press return> "); 
     scanf("%c%c%c", &first, &middle, &last);
     printf("Hello %c%c%c, let's see what your coins are worth.\n",
            first, middle, last);
 
     /* Get the count of each kind of coin. */ 
     printf("Number of quarters> "); 
     scanf("%d", &quarters); 
     printf("Number of dimes   > "); 
     scanf("%d", &dimes); 
     printf("Number of nickels > "); 
     scanf("%d", &nickels); 
     printf("Number of pennies > "); 
     scanf("%d", &pennies); 
 
     /* Compute the total value in cents. */
     total_cents = 25 * quarters + 10 * dimes +
                    5 * nickels + pennies;
 
     /* Find the value in dollars and change. */
     dollars = total_cents / 100; 
     change = total_cents % 100; 
 
     /* Display the value in dollars and change. */
     printf("\nYour coins are worth %d dollars and %d cents.\n",
            dollars, change);
 
     return (0);
}