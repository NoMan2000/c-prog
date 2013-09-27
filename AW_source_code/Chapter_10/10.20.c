Figure 10.20  Recursive Set Operations on Sets Represented as Character Strings
/*
 *  Functions to perform basic operations on sets of characters 
 *  represented as strings. Note: "Rest of set" is represented  as 
 *  &set[1], which is indeed the address of the rest of the set excluding 
 *  the first element.  This efficient representation, which does not 
 *  recopy the rest of the set, is an acceptable substring reference in 
 *  these functions only because the "rest of the set" is always passed 
 *  strictly as an input argument.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SETSIZ  65  /* 52 uppercase and lowercase letters, 10 digits, 
{, }, and '\0' 	*/
#define TRUE    1
#define FALSE   0

int is_empty(const char *set);
int is_element(char ele, const char *set);
int is_set(const char *set);
int is_subset(const char *sub, const char *set);
char *set_union(char *result, const char *set1, const char *set2);
void print_with_commas(const char *str);
void print_set(const char *set);
char *get_set(char *set);

/*
 *  Tries out set operation functions.
 */
int
main(void)
{
      char ele, set_one[SETSIZ], set_two[SETSIZ], set_three[SETSIZ];
 
      printf("A set is entered as a string of up to %d letters\n", 
SETSIZ - 3);
      printf("and digits enclosed in {} ");
      printf("(no duplicate characters)\n");
      printf("For example, {a, b, c} is entered as {abc}\n");
 
      printf("Enter a set to test validation function> ");
      get_set(set_one);
      putchar('\n');
      print_set(set_one);
      if (is_set(set_one))
            printf(" is a valid set\n");
      else
            printf(" is invalid\n");
 
      printf("Enter a single character, a space, and a set> ");
      while(isspace(ele = getchar()));  /* gets first character after white space 	*/
      get_set(set_one);
      printf("\n%c ", ele);
      if (is_element(ele, set_one))
            printf("is an element of ");
      else
            printf("is not an element of ");
      print_set(set_one);
 
      printf("\nEnter two sets to test set_union> ");
      get_set(set_one);
      get_set(set_two);
      printf("\nThe union of ");
      print_set(set_one);
      printf(" and ");
      print_set(set_two);
      printf(" is ");
      print_set(set_union(set_three, set_one, set_two));
      putchar('\n');

      return (0);
}

/*
 *  Determines if set is empty.  If so, returns 1;  if not, returns 0.
 */
int
is_empty(const char *set)
{
      return (set[0] == '\0');
}

/*
 *  Determines if ele is an element of set.
 */
int
is_element(char       ele,     /* input - element to look for in set	*/
           const char *set)    /* input - set in which to look for ele	*/
{
      int ans;

      if (is_empty(set))
            ans = FALSE;
      else if (set[0] == ele)
            ans = TRUE;
      else
            ans = is_element(ele, &set[1]);

      return (ans);
}

/*
 *  Determines if string value of set represents a valid set (no duplicate 
 *  elements)
 */
int
is_set(const char *set)
{
      int ans;

      if (is_empty(set))
            ans = TRUE;
      else if (is_element(set[0], &set[1]))
            ans = FALSE;
      else
            ans = is_set(&set[1]);
      return (ans);
}

/*
 *  Determines if value of sub is a subset of value of set.
 */
int
is_subset(const char *sub, const char *set)
{
      int ans;

      if (is_empty(sub))
            ans = TRUE;
      else if (!is_element(sub[0], set))
            ans = FALSE;
      else
            ans = is_subset(&sub[1], set);

      return (ans);
}

/*
 *   Finds the union of set1 and set2.
 *   Pre:  size of result array is at least SETSIZ;
 *         set1 and set2 are valid sets of characters and digits
 */
char *
set_union(char       *result,  /* output - space in which to store 
string result 	*/
          const char *set1,    /* input  - sets whose	*/
          const char *set2)    /*          union is being formed	*/
{
      char temp[SETSIZ];       /* local variable to hold result of call 
to set_union embedded in sprintf call	*/

      if (is_empty(set1))
            strcpy(result, set2);
      else if (is_element(set1[0], set2))
            set_union(result, &set1[1], set2);
      else
            sprintf(result, "%c%s", set1[0], 
set_union(temp, &set1[1], set2));

      return (result);
}

/*
 *  Displays a string so that each pair of characters is separated by a 
 *  comma and a space.
 */
void
print_with_commas(const char *str)
{
      if (strlen(str) == 1) {
            putchar(str[0]);
      } else {
            printf("%c, ", str[0]);
            print_with_commas(&str[1]);
      }
}

/*
 *  Displays a string in standard set notation.
 *  e.g.  print_set("abc") outputs {a, b, c}
 */
void
print_set(const char *set)
{
      putchar('{');
      if (!is_empty(set))
            print_with_commas(set);
      putchar('}');
}

/*
 *  Gets a set input as a string with brackets (e.g., {abc})
 *  and strips off the brackets.
 */
char *
get_set(char *set)   /* output - set string without brackets {} 	*/
{
      char inset[SETSIZ];

      scanf("%s", inset);
      strncpy(set, &inset[1], strlen(inset) - 2);
      set[strlen(inset) - 2] = '\0';
      return (set);
}