/* Draws a stick figure */

#include <stdio.h>
#include "drawHeaders.h"
/* Function prototypes are put into an external header file.*/
#include "drawHeaders.c"
/* The external function calls are put into a separate C file. */

int
main(void)
{

      /* Draw a circle. 	*/
      draw_circle();

      /* Draw a triangle. 	*/
      draw_triangle();

      /* Draw intersecting lines.	*/
      draw_intersect();

      return (0);
}
 
