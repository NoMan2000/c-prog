Figure 8.24  Function display_table and Helper Function display_quarter
/*
 *  Displays the sales table data in table form along with the row and column 
 *  sums.
 *  Pre:  sales, person_totals, quarter_totals, and num_rows are defined.
 *  Post: Values stored in the three arrays are displayed.
 */
void
display_table(double       sales[][NUM_QUARTERS], /* input */
              const double person_totals[],       /* input */
              const double quarter_totals[],      /* input */
              int          num_rows)              /* input */
{
      int       person;
      quarter_t quarter;

      /* Display heading */
      printf("%34cSales Summary\n%34c----- -------\n\n", ' ', ' ');
      printf("%12s%5c", "Salesperson", ' ');
      for  (quarter = fall;  quarter <= summer;  ++quarter){
	     display_quarter(quarter);
	     printf("%8c", ' ');
      }
      printf("TOTAL\n");
      printf("----------------------------------------");
      printf("----------------------------------------\n");

      /* Display table */
      for  (person = 0;  person < num_rows;  ++person) {
	  printf("%6d%4c", person, ' ');
	  for  (quarter = fall;  quarter <= summer;  ++quarter)
	      printf("%6c%8.2f", ' ', sales[person][quarter]);
	  printf("%6c%8.2f\n", ' ', person_totals[person]);
      }
      printf("----------------------------------------");
      printf("----------------------------------------\n");
      printf("QUARTER TOTALS ");
      for  (quarter = fall;  quarter <= summer;  ++quarter)
	  printf("%9.2f%5c", quarter_totals[quarter], ' ');
      printf("\n");
}
 
/*
 *  Display an enumeration constant of type quarter_t
 */
void
display_quarter(quarter_t quarter)
{
      switch (quarter) {
      case fall:    printf("Fall ");
		    break;

      case winter:  printf("Winter");
		    break;

      case spring:  printf("Spring");
		    break;

      case summer:  printf("Summer");
		    break;

      default:      printf("Invalid quarter %d", quarter);
      }
}