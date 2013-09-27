Figure 2.17  Revised Start of  main Function for Coin Evaluation

int
main(void)
{
      char first, middle, last; /* input - 3 initials           */
      int pennies, nickels;  /* input - count of each coin type */
      int dimes, quarters;   /* input - count of each coin type */
      int change;                /* output - change amount      */
      int dollars;               /* output - dollar amount      */
      int total_cents;           /* total cents                 */
      int year;                  /* current year                */

      /* Get the current year.                                  */
      printf("Enter the current year and press return> ");
      scanf("%d", &year);

      /* Get the program user's initials.                       */ 
      printf("Type in 3 initials and press return> "); 
      scanf("%c%c%c", &first, &middle, &last);
      printf("Hello %c%c%c, let's check your coins' value in %d.\n",
             first, middle, last, year);
      ...