Figure 8.12  Function Using a Sentinel-Controlled Loop to Store Input Data in an  Array
/*
 *  Gets data to place in dbl_arr until value of sentinel is encountered in
 *  the input.
 *  Returns number of values stored through dbl_sizep.
 *  Stops input prematurely if there are more than dbl_max data values before
 *  the sentinel or if invalid data is encountered.
 *  Pre:  sentinel and dbl_max are defined and dbl_max is the declared size of
 *        dbl_arr
 */
void
fill_to_sentinel(int     dbl_max,    /* input - declared size of dbl_arr	*/
		 double  sentinel,   /* input - end of data value in
						input list	*/
		 double  dbl_arr[],   /* output - array of data	*/
		 int    *dbl_sizep)   /* output - number of data values
						  stored in dbl_arr	*/
{
      double data;
      int    i, status;

      /* Sentinel input loop	*/
      i = 0;
      status = scanf("%lf", &data);
      while (status == 1  &&  data != sentinel  &&  i < dbl_max) {
	  dbl_arr[i] = data;
	  ++i;
	  status = scanf("%lf", &data);
      }

      /* Issues error message on premature exit	*/
      if (status != 1) {
	    printf("\n*** Error in data format ***\n");
	    printf("*** Using first %d data values ***\n", i);
      } else if (data != sentinel) {
	    printf("\n*** Error: too much data before sentinel ***\n");
	    printf("*** Using first %d data values ***\n", i);
      }

      /* Sends back size of used portion of array 	*/
      *dbl_sizep = i;
}