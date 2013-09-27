Figure 7.2  Program to Print Implementation-Specific Ranges
for Positive Numeric Data
/*
* Find implementation's ranges for positive numeric data
*/

#include <stdio.h>
#include <limits.h> /* definition of INT_MAX	*/
#include <float.h>  /* definitions of DBL_MIN, DBL_MAX  	*/

int
main(void)
{
      printf("Range of positive values of type int: 1 . . %d\n",
INT_MAX);
      printf("Range of positive values of type double: %e . . %e\n",
DBL_MIN, DBL_MAX);

      return (0);
}