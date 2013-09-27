Figure 8.9  Function to Add Two Arrays
/*
 *  Adds corresponding elements of arrays ar1 and ar2, storing the result in
 *  arsum.  Processes first n elements only.
 *  Pre:  First n elements of ar1 and ar2 are defined.  arsum's corresponding
 *        actual argument has a declared size >= n (n >= 0)
 */
void
add_arrays(const double ar1[],   /* input -                       */
           const double ar2[],   /*    arrays being added         */
           double       arsum[], /* output - sum of corresponding
                                       elements of ar1 and ar2    */
           int          n)       /* input - number of element
                                       pairs summed               */
{
      int i;

      /* Adds corresponding elements of ar1 and ar2               */
      for  (i = 0;  i < n;  ++i)
          arsum[i] = ar1[i] + ar2[i];
}