Figure 9.17  Program Segment That Validates Input Line before Storing Data Values
char data_line[STRSIZ], str[STRSIZ];
int n1, n2, error_mark, i;
 
scanline(data_line, STRSIZ);
error_mark = validate(data_line);
 
if (error_mark < 0) {
      /*  Stores in memory values from correct data line    */
      sscanf(data_line, "%d%d%s", &n1, &n2, str);
} else {
      /*  Displays line and marks spot where error detected    */
      printf("\n%s\n", data_line);
      for  (i = 0;  i < error_mark;  ++i)
          putchar(' ');
      putchar('/');
}
