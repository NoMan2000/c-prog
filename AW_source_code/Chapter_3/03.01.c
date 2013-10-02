/*
 * Converts distance in miles to kilometers.
 */

#include <stdio.h>                 /* printf, scanf definitions */
#define KMS_PER_MILE 1.609         /* conversion constant */

int
main(void)
{
      double miles;	/* input - distance in miles.  	*/
      double kms; 	/* output - distance in kilometers 	*/

      /* Get the distance in miles.               	*/
      printf("How many miles do you want to convert\n");
      scanf("%lf", &miles);
      
      /* Convert the distance to kilometers.      	*/
    kms = KMS_PER_MILE * miles;

         /* Distance in kilometers is 
              1.609 * distance in miles.           	*/

      /* Display the distance in kilometers.       	*/
    printf("You entered %f in miles and that converts to %f in kilometers\n", miles, kms);


      return (0);
}