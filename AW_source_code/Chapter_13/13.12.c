Figure 13.12  File Backup Using Arguments to Function main
/*
 *  Makes a backup of the file whose name is the first command line argument. 
 *  The second command line argument is the name of the new file.
 */
#include <stdio.h>
#include <stdlib.h>
 
int
main(int   argc,   /* input - argument count (including program name) */
     char *argv[]) /* input - argument vector                         */
{
      FILE *inp,    /* file pointers for input     */
           *outp;   /*    and backup files         */
      char  ch;     /* one character of input file */

      /* Open input and backup files if possible                      	*/
      inp = fopen(argv[1], "r");
      if (inp == NULL) {
            printf("\nCannot open file %s for input\n", argv[1]);
            exit(1);
      }
  
      outp = fopen(argv[2], "w");
      if (outp == NULL) {
            printf("\nCannot open file %s for output\n", argv[2]);
            exit(1);
      }

      /* Make backup copy one character at a time                    	 */
      for (ch = getc(inp);  ch != EOF;  ch = getc(inp))
         putc(ch, outp);

      /*  Close files and notify user of backup completion            	*/
      fclose(inp);
      fclose(outp);
      printf("\nCopied %s to %s\n", argv[1], argv[2]);

      return(0);
}