//Figure 8.22  Sales Analysis Main Function
/*
 *  Scans sales figures for one year and stores them in a table organized
 *  by salesperson and quarter. Displays the table and the annual totals
 *  for each person and the sales totals for each quarter
 */

#include <stdio.h>

#define SALES_FILE       "sales.dat"   /* name of sales data file */
#define NUM_QUARTERS     4             
#define NUM_SALES_PEOPLE 5

typedef enum 
      {fall, winter, spring, summer}
quarter_t;

int  scan_table(double sales[][NUM_QUARTERS], int num_rows);
void sum_rows(double row_sum[], double sales[][NUM_QUARTERS], int num_rows);
void sum_columns(double col_sum[], double sales[][NUM_QUARTERS], 
                 int num_rows);
void display_table(double sales[][NUM_QUARTERS], const double 
                   person_totals[], const double quarter_totals[], 
                   int num_rows);
/*  Insert function prototypes for any helper functions. */

int
main(void)
{
      double sales[NUM_SALES_PEOPLE][NUM_QUARTERS]; /* table of sales */
      double person_totals[NUM_SALES_PEOPLE];       /* row totals */
      double quarter_totals[NUM_QUARTERS];          /* column totals */
      int    status;

      status = scan_table(sales, NUM_SALES_PEOPLE);
      if (status == 1) {
            sum_rows(person_totals, sales, NUM_SALES_PEOPLE);
            sum_columns(quarter_totals, sales, NUM_SALES_PEOPLE);
            display_table(sales, person_totals, quarter_totals, 
                          NUM_SALES_PEOPLE);
      } 
      return (0);
}
