Figure 6.14  Stub for Function multiply_fractions
/*
 ***** STUB *****
 * Multiplies fractions represented by pairs of integers.
 * Pre:  n1, d1, n2, d2 are defined; 
 *       n_ansp and d_ansp are addresses of type int variables.
 * Post: product of n1/d1 and n2/d2 is stored in variables pointed 
 *       to by n_ansp and d_ansp.  Result is not reduced.
 */
void
multiply_fractions(int      n1, int   d1, /*  input - first fraction	*/
                   int      n2, int   d2, /*  input - second fraction	*/
                   int *n_ansp,           /*  output -	*/
		   int *d_ansp)           /*     product of 2 fractions	*/
{
      /* Displays trace message	*/
      printf("\nEntering multiply_fractions with\n");
      printf("n1 = %d, d1 = %d, n2 = %d, d2 = %d\n", n1, d1, n2, d2);

      /* Defines output arguments`	*/
      *n_ansp = 1;
      *d_ansp = 1;
}