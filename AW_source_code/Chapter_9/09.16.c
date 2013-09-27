Figure 9.16  String Function for a Greater-Than Operator That Ignores Case
#include <string.h>
#include <ctype.h>

#define STRSIZ 80

/*
 *  Converts the lowercase letters of its string argument to uppercase 
 *  leaving other characters unchanged.
 */
char *
string_toupper(char *str) /* input/output - string whose lowercase 
letters are to be replaced by uppercase	*/
{
      int i;

      for  (i = 0;  i < strlen(str);  ++i)
          if (islower(str[i]))
                str[i] = toupper(str[i]);
 
      return (str);
}
 
/*
 *  Compares two strings of up to STRSIZ characters ignoring the case of 
 *  the letters.  Returns the value 1 if str1 should follow str2 in an
 *  alphabetized list; otherwise returns 0
 */
int
string_greater(const char *str1,  /* input - 	*/
               const char *str2)  /*    strings to compare	*/
{
      char s1[STRSIZ], s2[STRSIZ];
 
      /*  Copies str1 and str2 so string_toupper can modify copies	*/
      strcpy(s1, str1);
      strcpy(s2, str2);
 
      return (strcmp(string_toupper(s1), string_toupper(s2)) > 0);
}