Figure 12.5  Outline and Function main for Database Inquiry Program
/*
 *  Displays all products in the database that satisfy the search 
 *  parameters specified by the program user.
 */
#include <stdio.h>
#include <string.h>
 
#define MIN_STOCK    1111    /* minimum stock number 	*/
#define MAX_STOCK    9999    /* maximum stock number 	*/
#define MAX_PRICE    1000.00 /* maximum product price	*/
#define STR_SIZ      80      /* number of characters in a string	*/
 
typedef struct {             /* product structure type	*/
      int    stock_num;           /* stock number	*/
      char   category[STR_SIZ];
      char   tech_descript[STR_SIZ];
      double price;
} product_t;
 
typedef struct {             /* search parameter bounds type	*/
      int    low_stock, high_stock;
      char   low_category[STR_SIZ], high_category[STR_SIZ];
      char   low_tech_descript[STR_SIZ], high_tech_descript[STR_SIZ];    
      double low_price, high_price;
} search_params_t;
 
search_params_t get_params(void);
void display_match(FILE *databasep, search_params_t params);
 
/* Insert prototypes of functions needed by get_params and display_match */
 
int
main(void)
{
      char            inv_filename[STR_SIZ];  /* name of inventory file	*/
      FILE           *inventoryp;             /* inventory file pointer	*/
      search_params_t params;                 /* search parameter
bounds	*/
 
      /*  Get name of inventory file and open it	*/
      printf("Enter name of inventory file> ");
      scanf("%s", inv_filename);
      inventoryp = fopen(inv_filename, "rb");
 
      /*  Get the search parameters 	*/
      params = get_params();
 
      /*  Display all products that satisfy the search parameters	*/
      display_match(inventoryp, params);
 
      return(0);
}
 
/*
 *  Prompts the user to enter the search parameters                     
 */
search_params_t
get_params(void)
{
   /* body of get_params to be inserted */
}
 
/*
 *  Displays records of all products in the inventory that satisfy search
 *  parameters.
 *  Pre:  databasep accesses a binary file of product_t records that has 
 *        been opened as an input file, and params is defined
 */
void
display_match(FILE           *databasep, /* input - file pointer to binary 
                                                    database file	*/
              search_params_t params)    /* input - search parameter 
bounds  	*/
{
   /* body of display_match to be inserted */
}
 
/*  Insert functions needed by get_params and display_match	*/