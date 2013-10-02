
/*
 * Computes the circumference of a circle with radius r.
 * Pre:  r is defined and is > 0.
 *       PI is a constant macro representing an approximation of pi.
 */
double
find_circum(double r)
{
     return (2.0 * PI * r);
}


/*
 * Computes the area of a circle with radius r.
 * Pre:  r is defined and is > 0.
 *       PI is a constant macro representing an approximation of pi.
 *       Library math.h is included.
 */
double
find_area(double r)
{
     return (PI * pow(r, 2));
}