Figure 6.6  Program to Sort Three Numbers
/*
 * Tests function order by ordering three numbers
 */
#include <stdio.h>

void order(double *smp, double *lgp); 

int
main(void)
{
        double num1, num2, num3; /* three numbers to put in order 	*/

        /* Gets test data 	*/
        printf("Enter three numbers separated by blanks> ");

        scanf("%lf%lf%lf", &num1, &num2, &num3);
        /* Orders the three numbers 	*/
        order(&num1, &num2);
        order(&num1, &num3);
        order(&num2, &num3);

        /* Displays results 	*/
        printf("The numbers in ascending order are: %.2f %.2f %.2f\n", 
num1, num2, num3);

        return (0);
}

/*
 * Arranges arguments in ascending order.
 * Pre:  smp and lgp are addresses of defined type double variables
 * Post: variable pointed to by smp contains the smaller of the type 
 *       double values; variable pointed to by lgp contains the larger
 */
void
order(double *smp, double *lgp)     /* input/output */
{
        double temp; /* temporary variable to hold one number during swap 	*/
        /* Compares values pointed to by smp and lgp and switches if necessary	*/
        if (*smp > *lgp) {
                temp = *smp;
                *smp = *lgp;
                *lgp = temp;
        }
}

Enter three numbers separated by blanks> 7.5 9.6 5.5
The numbers in ascending order are: 5.50 7.50 9.60