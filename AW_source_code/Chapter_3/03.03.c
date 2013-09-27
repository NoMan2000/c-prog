Figure 3.3  Calculating the Area and the Circumference of a Circle
/*
 * Calculates and displays the area and circumference of a circle
 */

#include <stdio.h>
#define PI 3.14159

int
main(void)
(continued)
Figure 3.3  (continued)
{
      double radius; /* input - radius of a circle	*/
      double area;   /* output - area of a circle 	*/
      double circum; /* output - circumference 	*/

      /* Get the circle radius */
      printf("Enter radius> ");
      scanf("%lf", &radius);

      /* Calculate the area */
      area = PI * radius * radius;

      /* Calculate the circumference */
      circum = 2 * PI * radius;

      /* Display the area and circumference */
      printf("The area is %.4f\n", area);
      printf("The circumference is %.4f\n", circum);

      return (0);
}

Enter radius> 5.0
The area is 78.5397
The circumference is 31.4159