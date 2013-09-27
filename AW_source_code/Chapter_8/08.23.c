Figure 8.23  Function scan_table and Helper Function initialize
/*
 *  Scans the sales data from SALES_FILE and computes and stores the sales 
 *  results in the sales table. Flags out-of-range data and data format 
 *  errors.
 *  Post:  Each entry of sales represents the sales total for a particular 
 *         salesperson and quarter.
 *         Returns 1 for successful table scan, 0 for error in scan.
 *  Calls: initialize to initialize table to all zeros
 */ 
int  
scan_table(double sales[][NUM_QUARTERS], /* output */
           int num_rows)                 /* input  */
{
      double    trans_amt;        /* transaction amount */
      int       trans_person;     /* salesperson number */
      quarter_t quarter;          /* sales quarter      */
      FILE     *sales_filep;      /* file pointer to sales file */
      int       valid_table = 1;  /* data valid so far  */
      int       status;           /* input status       */
      char      ch;               /* one character in bad line */

      /*  Initialize table to all zeros */
      initialize(sales, num_rows, 0.0);

      /*  Scan and store the valid sales data */
      sales_filep = fopen(SALES_FILE, "r");
      for  (status = fscanf(sales_filep, "%d%d%lf", &trans_person,
                            &quarter, &trans_amt);
	    status == 3  &&  valid_table;
            status = fscanf(sales_filep, "%d%d%lf", &trans_person,
                            &quarter, &trans_amt)) {
          if (fall <= quarter  &&  quarter <= summer  &&
              trans_person >= 0  &&  trans_person < num_rows) {
                sales[trans_person][quarter] += trans_amt;
          } else {
                printf("Invalid salesperson or quarter -- \n");
                printf("  person is %d, quarter is ", trans_person);
                display_quarter(quarter);
                printf("\n\n");
                valid_table = 0;
          }
      }

      if (!valid_table) {          /* error already processed */
            status = 0;
      } else if (status == EOF) {  /* end of data without error */
            status = 1;
      } else {                     /* data format error */
            printf("Error in sales data format. Revise data.\n");
            printf("ERROR HERE >>> ");
            for  (status = fscanf(sales_filep, "%c", &ch);  
		  status == 1  &&  ch != '\n';
                  status = fscanf(sales_filep, "%c", &ch)) 
                printf("%c", ch);
            printf(" <<<\n");
            status = 0;
      }
      return (status);
}
 
/*
 *  Stores value in all elements of sales.
 *  Pre:  value is defined and num_rows is the number of rows in
 *        sales.
 *  Post: All elements of sales have the desired value.
 */
void 
initialize(double sales[][NUM_QUARTERS], /* output */
           int    num_rows,              /* input  */
           double value)                 /* input  */
{
      int       row;
      quarter_t quarter;

      for  (row = 0;  row < num_rows;  ++row)
          for  (quarter = fall;  quarter <= summer;  ++quarter)
              sales[row][quarter] = value;
}