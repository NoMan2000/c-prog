Figure 10.10  Recursive factorial Function
/*
 *  Compute n! using a recursive definition
 *  Pre:  n >= 0
 */
int
factorial(int n)
{
      int ans;

      if (n == 0)
            ans = 1;
      else
            ans = n * factorial(n - 1);

      return (ans);
}