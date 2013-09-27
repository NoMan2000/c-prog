Figure 9.8  Demonstration of Whole-Line Input
/* 
 *  Numbers and double spaces lines of a document. Lines longer than 
 *  LINE_LEN - 1 characters are split on two lines.
 */

#include <stdio.h>
#include <string.h>

#define LINE_LEN 80
#define NAME_LEN 40

int 
main(void)
{
      char line[LINE_LEN], inname[NAME_LEN], outname[NAME_LEN];
      FILE *inp, *outp;
      char *status;  
      int i = 0;

      printf("Name of input file> ");
      scanf("%s", inname);
      printf("Name of output file> ");
      scanf("%s", outname);

      inp = fopen(inname, "r");
      outp = fopen(outname, "w");

      for  (status = fgets(line, LINE_LEN, inp);
            status != 0;
            status = fgets(line, LINE_LEN, inp)) {
          if (line[strlen(line) - 1] == '\n')
                line[strlen(line) - 1] = '\0';
          fprintf(outp, "%3d>> %s\n\n", ++i, line);
      }
 
      return (0);
}

File used as input

In the early 1960s, designers and implementers of operating
systems were faced with a significant dilemma. As people's
expectations of modern operating systems escalated, so did
the complexity of the systems themselves. Like other
programmers solving difficult problems, the systems
programmers desperately needed the readability and
modularity of a powerful high-level programming language.

Output file
  1>> In the early 1960s, designers and implementers of operating
  2>> systems were faced with a significant dilemma. As people's
  3>> expectations of modern operating systems escalated, so did
  4>> the complexity of the systems themselves. Like other
  5>> programmers solving difficult problems, the systems
  6>> programmers desperately needed the readability  nd
  7>> modularity of a powerful high-level programming language.