Figure 13.10  Conditional Compilation of Tracing printf Calls
/*
 *  Computes an integer quotient (m/n) using subtraction
 */
int
quotient(int m, int n)
{
      int ans;

#if defined (TRACE_VERBOSE)
      printf("Entering quotient with m = %d, n = %d\n", 
m, n);
#elif defined (TRACE_BRIEF)
      printf(" => quotient(%d, %d)\n", m, n);
#endif

      if (n > m)
            ans = 0;
      else
            ans = 1 + quotient(m - n, n);

#if defined (TRACE_VERBOSE)
      printf("Leaving quotient(%d, %d) with result = %d\n", m, n, ans);
#elif defined (TRACE_BRIEF)
      printf("quotient(%d, %d) => %d\n", m, n, ans);
#endif

      return (ans);
}