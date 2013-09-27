Figure 13.8  Function factorial with Premature Exit on Negative Data
/*
 * Computes n!
 * n is greater than or equal to zero -- premature exit on negative data
 */
int
factorial(int n)
{
      int i,            /* local variables */
          product = 1;
 
      if (n < 0) {
            printf("\n***Function factorial reports ");
            printf("ERROR:  %d! is undefined***\n", n);
            exit(1);
      } else {
            /* Compute the product n x (n-1) x (n-2) x ... x 2 x 1 */
            for  (i = n;  i > 1;  --i) {
                product = product * i;
            }

            /* Return function result */
            return (product);
      }
}