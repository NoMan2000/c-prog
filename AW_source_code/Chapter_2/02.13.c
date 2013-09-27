/* Converts distances from miles to kilometers.    */

#include <stdio.h>    /* printf, scanf definitions */
#define KMS_PER_MILE 1.609 /* conversion constant  */

int
main(void)
{
      double miles,  /* distance in miles	*/
             kms;    /* equivalent distance in kilometers	*/

/* Terrible programming to not ask for what you want before it is echoed to the end user */

      /* Get and echo the distance in miles. */
      scanf("%lf", &miles);
      printf("The distance in miles is %.2f.\n", miles);

      /* Convert the distance to kilometers. */
      kms = KMS_PER_MILE * miles;

      /* Display the distance in kilometers. */
      printf("That equals %.2f kilometers.\n", kms);

      return (0);
}

