Figure 12.8  Functions display_match, menu_choose, and match
/*  
 *  Displays a lettered menu with the current values of search parameters.
 *  Returns the letter the user enters.  A letter in the range a..h selects
 *  a parameter to change; q quits, accepting search parameters shown.
 *  Post:  first non-whitespace character entered is returned
 */
char
menu_choose(search_params_t params) /* input - current search parameter bounds 	*/
{
      char choice;

      printf("Select by letter a search parameter to set or enter ");
      printf("q to\naccept parameters shown.\n\n");
      printf("     Search parameter                       "); 
      printf("Current value\n\n");
      printf("[a]  Low bound for stock number              %4d\n",
             params.low_stock);
      printf("[b]  High bound for stock number                  %4d\n",
             params.high_stock);
      printf("[c]  Low bound for category                       %s\n",
             params.low_category);
      printf("[d]  High bound for category                      %s\n",
             params.high_category);
      printf("[e]  Low bound for technical description          %s\n",
             params.low_tech_descript);
      printf("[f]  High bound for technical description         %s\n",
             params.high_tech_descript);
      printf("[g]  Low bound for price                          $%7.2f\n",
             params.low_price);
      printf("[h]  High bound for price                         $%7.2f\n\n",
             params.high_price); 

      printf("Selection> ");
      scanf(" %c", &choice);

      return (choice);
}

/*
 *  Determines whether record prod satisfies all search parameters
 */
int
match(product_t       prod,    /*  input - record to check         */
      search_params_t params)  /*  input - parameters to satisfy   */
{
      return (strcmp(params.low_category, prod.category) <= 0            &&
              strcmp(prod.category, params.high_category) <= 0           &&
              strcmp(params.low_tech_descript, prod.tech_descript) <= 0  &&
              strcmp(prod.tech_descript, params.high_tech_descript) <= 0 &&
              params.low_price <= prod.price                             &&
              prod.price <= params.high_price);
}
/*
 *  *** STUB ***
 *  Displays each field of prod.  Leaves a blank line after the product
 *  display.
 */
void
show(product_t prod)
{
      printf("Function show entered with product number %d\n",
             prod.stock_num);
}

/*
 *  Displays records of all products in the inventory that satisfy search
 *  parameters.
 *  Pre:  databasep accesses a binary file of product_t records that has 
 *        been opened as an input file, and params is defined
 */
void
display_match(FILE           *databasep,  /*  file pointer to binary 
database file  	*/
              search_params_t params)     /*  input - search parameter bounds       	*/
{
      product_t next_prod;       /* current product from database	*/
      int       no_matches = 1;  /* flag indicating if no matches have been found   	*/
      int       status;          /* input file status	*/

      /*  Advances to first record with a stock number greater than or equal to lower bound.	*/
      for  (status = fread(&next_prod, sizeof (product_t), 1, databasep);
            status == 1  &&  params.low_stock > next_prod.stock_num;
            status = fread(&next_prod, sizeof (product_t), 1, databasep)) {}

      /*  Displays a list of the products which satisfy the search 
parameters      	 */
      printf("\nProducts satisfying the search parameters:\n");
      while (next_prod.stock_num <= params.high_stock  &&
             status == 1) {
          if (match(next_prod, params)) {
                no_matches = 0;
                show(next_prod);
          }
          status = fread(&next_prod, sizeof (product_t), 1, databasep);
      }

      /*  Displays a message if no products found 	*/
      if (no_matches)
            printf("Sorry, no products available\n");                               
}