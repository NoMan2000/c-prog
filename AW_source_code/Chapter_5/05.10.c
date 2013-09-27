Figure 5.10  Sentinel-Controlled while Loop
/* Compute the sum of a list of exam scores. */

#include <stdio.h>

#define SENTINEL -99

int
main(void)
{
        int sum = 0,   /* output - sum of scores input so far	*/
            score;     /* input - current score	*/

        /* Accumulate sum of all scores.	*/
        printf("Enter first score (or %d to quit)> ", SENTINEL);
        scanf("%d", &score);       /* Get first score.	*/
        while (score != SENTINEL) {
            sum += score;
            printf("Enter next score (%d to quit)> ", SENTINEL);
            scanf("%d", &score);   /* Get next score.	*/
        }
        printf("\nSum of exam scores is %d\n", sum);

        return (0);
}