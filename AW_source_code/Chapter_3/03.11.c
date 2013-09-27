Figure 3.11  Function Prototypes and Main Function for Stick Figure
/*
 * Draws a stick figure
 */

#include <stdio.h>

/* function prototypes 	*/

void draw_circle(void);      /* Draws a circle  	*/

void draw_intersect(void);   /* Draws intersecting lines 	*/

void draw_base(void);        /* Draws a base line   	*/

void draw_triangle(void);    /* Draws a triangle   	*/

int
main(void)
{
      /* Draw a circle.  */
      draw_circle();

      /* Draw a triangle.  */
      draw_triangle();

      /* Draw intersecting lines.  */
      draw_intersect();

      return (0);
}