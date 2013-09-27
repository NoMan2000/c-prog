/* Converts distances from miles to kilometers.  	*/

#include <stdio.h>    /* printf, scanf, fprint, fscanf, fopen, fclose definitions        	*/
#define KMS_PER_MILE 1.609 /* conversion constant 	*/

int
main(void)
{
      double miles, /* distance in miles	*/
             kms;   /* equivalent distance in kilometers	*/
      FILE   *inp,  /* pointer to input file	*/
             *outp; /* pointer to output file	*/

      /* Open the input and output files.    */
      inp = fopen("b:distance.dat", "r");
      outp = fopen("b:distance.out", "w");

      /* Get and echo the distance in miles. */
      fscanf(inp, "%lf", &miles);
      fprintf(outp, "The distance in miles is %.2f.\n", miles);

      /* Convert the distance to kilometers. */
      kms = KMS_PER_MILE * miles;

      /* Display the distance in kilometers. */
      fprintf(outp, "That equals %.2f kilometers.\n", kms);

      /* Close files. */
      fclose(inp);
      fclose(outp);

      return (0);
}
