Figure 5.13  Nested Counting Loop Program
/*
 * Illustrates a pair of nested counting loops
 */

#include <stdio.h>

int
main(void)
{
      int i, j;   /* loop control variables */

      printf("           I    J\n");    	/* prints column labels 	*/

      for  (i = 1;  i < 4;  ++i) {   	/* heading of outer for loop 	*/
	  printf("Outer %6d\n", i);
	  for  (j = 0;  j < i;  ++j) {  	/* heading of inner loop 	*/
	      printf("  Inner%9d\n", j);
	  }   /* end of inner loop */
      }   /*  end of outer loop */

      return (0);
}

	   I   J
Outer      1
  Inner        0
Outer      2
  Inner        0
  Inner        1
Outer      3
  Inner        0
  Inner        1
  Inner        2
