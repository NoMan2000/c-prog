/* Draws a house */

 #include <graphics.h>

 int
 main(void)
 {
initwindow(640, 500, "House - press a key to close", 100, 50);

 /* Define corners of house */
 int x1 = 100; int y1 = 200; /* top-left corner */
 int x2 = 300; int y2 = 100; /* roof peak */
 int x3 = 500; int y3 = 200; /* top-right corner */
 int x4 = 500; int y4 = 400; /* bottom-right corner */
 int x5 = 325; int y5 = 400; /* bottom-right corner of door */
 int x6 = 275; int y6 = 325; /* top-left corner of door */

 /* Draw roof. */
 line(x1, y1, x2, y2); /* Draw line from (x1, y1) to (x2, y2) */
 line(x2, y2, x3, y3); /* Draw line from (x2, y2) to (x3, y3) */

 /* Draw rest of house. */
 rectangle(x1, y1, x4, y4);

 /* Draw door. */
 rectangle(x5, y5, x6, y6);

 getch(); /* pause until user presses a key */
 closegraph(); /* close the window */

 return(0);
}