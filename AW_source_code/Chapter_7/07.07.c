Figure 7.7  Using a Function Parameter
/*
 * Evaluate a function at three points, displaying results.
 */
void
evaluate(double f(double f_arg), double pt1, double pt2, double pt3)
{
      printf("f(%.5f) = %.5f\n", pt1, f(pt1));
      printf("f(%.5f) = %.5f\n", pt2, f(pt2));
      printf("f(%.5f) = %.5f\n", pt3, f(pt3));
}