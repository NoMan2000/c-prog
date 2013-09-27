Figure 5.11  Batch Version of Sum of Exam Scores Program
/*
 *  Compute the sum of the list of exam scores stored in the
 *  file scores.dat
 */

#include <stdio.h>       /* defines fopen, fclose, fscanf,
			    fprintf, and EOF	*/

int
main(void)
{
      FILE *inp;          /* input file pointer   	*/
      int   sum = 0,      /* sum of scores input so far	*/
	    score,        /* current score 	*/
	    input_status; /* status value returned by fscanf	*/
(continued)
Figure 5.10  (continued)
      inp = fopen("scores.dat", "r");

      printf("Scores\n");

      input_status = fscanf(inp, "%d", &score);
      while (input_status != EOF) {
	  printf("%5d\n", score);
	  sum += score;
	  input_status = fscanf(inp, "%d", &score);
      }

      printf("\nSum of exam scores is %d\n", sum);
      fclose(inp);

      return (0);
}


Scores
   55
   33
   77

Sum of exam scores is 165