Figure 10.2  Recursive Function multiply
/*
 *  Performs integer multiplication using + operator.
 *  Pre:   m and n are defined and n > 0
 *  Post:  returns m * n
 */
int
multiply(int m, int n)
{
      int ans;

      if (n == 1)
            ans = m;     /* simple case */
      else
            ans = m + multiply(m, n  - 1);  /* recursive step */

      return (ans);
}