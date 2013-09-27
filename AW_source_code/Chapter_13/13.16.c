Figure 13.16  Macro Expansions of Macro Calls from Fig. 13.15
         Version 1	            Version 2

SQUARE(x + y)	SQUARE(x + y)
    becomes	    becomes
x + y * x + y	((x + y) * (x + y))
Problem: multiplication done                
         before addition.

SQUARE(m) / SQUARE(n)	SQUARE(m) / SQUARE(n)
    becomes	    becomes
m * m / n * n 	((m) * (m)) / ((n) * (n))
Problem: multiplication and
         division are of equal precedence;
         they are performed left to right.    