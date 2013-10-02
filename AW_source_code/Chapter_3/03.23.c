/*
 * Multiplies its first argument by the power of 10 specified
 * by its second argument.
 * Pre : x and n are defined and math.h is included.
 */
double
scale(double x, int n)
{
     double scale_factor;     /* local variable */
     scale_factor = pow(10, n);

     return (x * scale_factor);
}
