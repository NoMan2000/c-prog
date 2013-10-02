/* Draws a stick figure */

#include <stdio.h>
#include "drawHeaders.h"
/* Function prototypes are put into an external header file.*/
#include "drawHeaders.c"

/* You would probably split these functions into header and different C files at this point. */

/*
 * Draws a circle
 */
void
draw_circle(void)
{
      printf("   *   \n");
      printf(" *   * \n");
      printf("  * *  \n");
}

/*
 * Draws intersecting lines
 */
void
draw_intersect(void)
{
      printf("  / \\  \n"); /* Use 2 \'s to print 1 */
      printf(" /   \\ \n");
      printf("/     \\\n");
}

/*
 * Draws a base line
 */
void
draw_base(void)

{
      printf("-------\n");
}

/*
 * Draws a triangle
 */
void
draw_triangle(void)
{
      draw_intersect();
      draw_base();
}




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
 
