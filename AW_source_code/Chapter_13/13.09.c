Figure 13.9  Conditional Compilation of Tracing printf Calls
/*
 *  Computes an integer quotient (m/n) using subtraction
 */
int
quotient(int m, int n)
{
      int ans;
#if defined (TRACE)
      printf("Entering quotient with m = %d, n = %d\n", 
m, n);
#endif

      if (n > m)
            ans = 0;
      else
            ans = 1 + quotient(m - n, n);

#if defined (TRACE)
      printf("Leaving quotient(%d, %d) with result = %d\n", m, n, ans);
#endif

      return (ans);
}