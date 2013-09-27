Figure 5.7  Function to Compute Factorial
/*
* Computes n!
* Pre: n is greater than or equal to zero
*/
int
factorial(int n)

(continued)
Figure 5.6  (continued)
{
      int i,         /* local variables */
          product;   /* accumulator for product computation */

      product = 1;
      /* Computes the product n x (n-1) x (n-2) x ... x 2 x 1 */
      for (i = n;  i > 1;  --i) {
           product = product * i;
      }

      /* Returns function result */
      return (product);
}
