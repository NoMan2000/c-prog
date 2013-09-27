Figure 5.5  Using a for Statement in a Counting Loop
/* Process payroll for all employees */
total_pay = 0.0;
for  (count_emp = 0; 		/* initialization 	*/
      count_emp < number_emp; 	/* loop repetition condition	*/
      count_emp += 1) {		/* update 	*/
     printf("Hours> ");
     scanf("%lf", &hours);
     printf("Rate > $");
     scanf("%lf", &rate);
     pay = hours * rate;
     printf("Pay is $%6.2f\n\n", pay);
     total_pay = total_pay + pay;
}
printf("All employees processed\n");
printf("Total payroll is $%8.2f\n", total_pay);                       }