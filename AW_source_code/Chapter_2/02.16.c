Figure 2.16  A Program with a Run-time Error
111 #include <stdio.h>
262
263 int
264 main(void)
265 {
266       int    first, second;
267       double temp, ans;
268
269       printf("Enter two integers> ");
270       scanf("%d%d", &first, &second);
271       temp = second / first;
272       ans = first / temp;
273       printf("The result is %.3f\n", ans);
274
275       return (0);
276 }

Enter two integers> 14 3
Arithmetic fault, divide by zero at line 272 of routine main