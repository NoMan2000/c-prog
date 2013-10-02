/*
 * Calculates and displays the area and circumference of a circle
 */

#include <stdio.h>
#define PI 3.14159

int
main(void)
{
      double radius;    /* input - radius of a circle  */
      double area;      /* output - area of a circle   */
      double circum;    /* output - circumference      */

      /* Get the circle radius */
      printf("What is the circumference of your circle?\n");
      scanf("%lf", &radius);
      /* Calculate the area */
         /* Assign PI * radius * radius to area. */

      area = PI * radius * radius;  

      /* Calculate the circumference */
         /* Assign 2 * PI * radius to circum. */
      circum = 2 * PI * radius;

      /* Display the area and circumference */
      printf("%.2f is the area and %.2f is the circumference\n", area, circum);
      /* Use %d to get an interesting error. */

      return (0);
}