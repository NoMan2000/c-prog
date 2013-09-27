Figure 9.15  Implementation of scanline Function Using getchar
/*
 *  Gets one line of data from standard input.  Returns an empty string on 
 *  end of file.  If data line will not fit in allotted space, stores 
 *  portion that does fit and discards rest of input line.
 */
char *
scanline(char *dest,     /* output - destination string */
	 int   dest_len) /* input  - space available in dest */
{
      int i, ch;

      /*  Gets next line one character at a time. */
      i = 0;
      for  (ch = getchar();
	    ch != '\n'  &&  ch != EOF   &&  i < dest_len - 1;
            ch = getchar())
          dest[i++] = ch;
      dest[i] = '\0';
 
      /*  Discards any characters that remain on input line */
      while (ch != '\n'  &&  ch != EOF)
          ch = getchar();
 
      return (dest);
}