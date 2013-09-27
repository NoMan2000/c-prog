Figure 9.22  Flawed scanline Returns Address of Deallocated Space
/*
 *  Gets one line of data from standard input.  Returns an empty string on end 
 *  of file.  If data line will not fit in allotted space, stores portion that 
 *  does fit and discards rest of input line.
 **** Error:  returns address of space that is immediately deallocated.
 */
char *
scanline(void)
{
      char dest[MAX_STR_LEN];
      int  i, ch;

      /*  Get next line one character at a time.	*/
      i = 0;
      for  (ch = getchar();
            ch != '\n'  && ch != EOF  &&  i < MAX_STR_LEN - 1;
            ch = getchar())
          dest[i++] = ch;
      dest[i] = '\0';

      /*  Discard any characters that remain on input line	*/
      while (ch != '\n'  &&  ch != EOF)
          ch = getchar();

      return (dest);
}