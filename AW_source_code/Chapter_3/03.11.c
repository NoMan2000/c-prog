/*
 * Draws a stick figure
 */

#include <stdio.h>

/* function prototypes 	*/

void draw_circle(void){};      /* Draws a circle  	*/

void draw_intersect(void){};   /* Draws intersecting lines 	*/

void draw_base(void){};        /* Draws a base line   	*/

void draw_triangle(void){};    /* Draws a triangle   	*/

/* Note that without the braces after the function definition, the compiler will return an error.

int
main(void)
{
      /* Draw a circle.  */
      draw_circle();

      /* Draw a triangle.  */
      draw_triangle();

      /* Draw intersecting lines.  */
      draw_intersect();
      
      draw_base();

      return (0);
}