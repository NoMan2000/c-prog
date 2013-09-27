Figure 13.13  Program Using a Macro with Formal Parameters
/*  Shows the definition and use of a macro  	*/

#include <stdio.h>

#define LABEL_PRINT_INT(label, num) printf("%s = %d", (label), (num))

int
main(void)
{
      int r = 5, t = 12;

      LABEL_PRINT_INT("rabbit", r);
      printf("     ");
      LABEL_PRINT_INT("tiger", t + 2);
      printf("\n");

      return(0);
}
rabbit = 5     tiger = 14