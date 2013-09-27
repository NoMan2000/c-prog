Figure 5.14  Validating Input Using do-while Statement
/*
 * Returns the first integer between n_min and n_max entered as data.
 * Pre : n_min <= n_max
 * Post: Result is in the range n_min through n_max.
 */
int
get_int (int n_min, int n_max)
{
	int  in_val, 	/* input - number entered by user	*/
	     status;	/* status value returned by scanf	*/
	char skip_ch;	/* character to skip 	*/
	int  error; 	/* error flag for bad input	*/
(continued)
Figure 5.13  (continued)
	/* Get data from user until in_val is in the range.	*/
	do {
	     /* No errors detected yet. */
	     error = 0;
	     /* Get a number from the user. */
	     printf("Enter an integer in the range from %d ", n_min);
	     printf("to %d inclusive> ", n_max);
	     status = scanf("%d", &in_val);

	     /* Validate the number. */
	     if (status != 1) {  /* in_val didn't get a number */
		 error = 1;
		 scanf("%c", &skip_ch);
                 printf("Invalid character >>%c>>. ", skip_ch);
                 printf("Skipping rest of line.\n");
             } else if (in_val < n_min  ||  in_val > n_max) {
                 error = 1;
                 printf("Number %d is not in range.\n", in_val);
             }

             /* Skip rest of data line. */
             do
                  scanf("%c", &skip_ch);
             while (skip_ch != '\n');
        } while (error);

	return (in_val);
}
