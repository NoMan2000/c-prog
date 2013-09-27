Figure 13.15  Macro Calls Showing Importance of Parentheses in Macro Body
         Version 1	             Version 2

#define SQUARE(n)  n * n	#define SQUARE(n)  ((n) * (n))

                 . . .
                 double x = 0.5, y = 2.0;
                 int     n = 4, m = 12;

                 printf("(%.2f + %.2f)squared = %.2f\n\n",
                          x, y, SQUARE(x + y));

                 printf("%d squared divided by\n", m);
                 printf("%d squared is %d\n", n,
                          SQUARE(m) / SQUARE(n));

 (0.5 + 2.0)squared = 3.5		(0.5 + 2.0)squared = 6.25

 12 squared divided by			12 squared divided by
 4 squared is 144					4 squared is 9