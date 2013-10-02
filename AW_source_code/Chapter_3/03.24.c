/*
 * Tests function scale.
 */
#include <stdio.h>
#include <math.h>

/* Function prototype */
double scale(double x, int n);

/*                                     information flow	 */

double
scale(double x, int n) //              	 formal parameters
{
     double scale_factor;     /* local variable - 10 to power n */

     scale_factor = pow(10, n);

     return (x * scale_factor);
}

int
main(void)
{
     double num_1;
     int num_2;

     /* Get values for num_1 and num_2 */
     printf("Enter a real number> ");
     scanf("%lf", &num_1);
     printf("Enter an integer> ");
     scanf("%d", &num_2);

     /* Call scale and display result. */
     printf("Result of call to function scale is %f\n",
            scale(num_1, num_2));    //actual arguments

     return (0);
}




/*Enter a real number> 2.5
Enter an integer> -2
Result of call to function scale is 0.025 */