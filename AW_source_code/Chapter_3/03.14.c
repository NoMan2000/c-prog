Figure 3.14  Program to Draw a Stick Figure
/* Draws a stick figure */

#include <stdio.h>

/* Function prototypes */
void draw_circle(void);	/* Draws a circle	*/

void draw_intersect(void);	/* Draws intersecting lines	*/

void draw_base(void);	/* Draws a base line 	*/

void draw_triangle(void);	/* Draws a triangle	*/

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