Figure 10.12  Iterative Function factorial
/*
 * Computes n!
 * Pre: n is greater than or equal to zero
 */
int
factorial(int n)
{
    int i,            /* local variables */
        product = 1;

    /* Compute the product n x (n-1) x (n-2) x ... x 2 x 1 */
    for  (i = n;  i > 1;  --i) {
        product = product * i;
    }

    /* Return function result */
    return (product);
}