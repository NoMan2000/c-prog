Figure 5.4  Program to Compute Company Payroll
/* Compute the payroll for a company */

#include <stdio.h>

int
main(void)
{
      double total_pay; 	/* company payroll 	*/
      int    count_emp; 	/* current employee 	*/
      int    number_emp; 	/* number of employees 	*/
      double hours; 	/* hours worked 	*/
      double rate;      /* hourly rate 	*/
      double pay; 	/* pay for this period 	*/

      /* Get number of employees. */
      printf("Enter number of employees> ");
      scanf("%d", &number_emp);

      /* Compute each employee's pay and add it to the payroll. */
      total_pay = 0.0;
      count_emp = 0;
      while (count_emp < number_emp) {
	     printf("Hours> ");
	     scanf("%lf", &hours);
	     printf("Rate > $");
	     scanf("%lf", &rate);
	     pay = hours * rate;
	     printf("Pay is $%6.2f\n\n", pay);
	     total_pay = total_pay + pay;              /* Add next pay. */
	     count_emp = count_emp + 1;
      }
      printf("All employees processed\n");
      printf("Total payroll is $%8.2f\n", total_pay);

      return (0);
}

Enter number of employees> 3
Hours> 50
Rate > $5.25
Pay is $262.50
Hours> 6
Rate > $5.00
Pay is $ 30.00

Hours> 15
Rate > $7.00
Pay is $105.00

All employees processed
Total payroll is $  397.50