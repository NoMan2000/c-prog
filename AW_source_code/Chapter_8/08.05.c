Figure 8.5  Function fill_array
/*
 * Sets all elements of its array parameter to in_value.
 * Pre:  n and in_value are defined.
 * Post: list[i] = in_value, for 0 <= i < n.
 */
void
fill_array (int list[],    /* output - list of n integers	*/
            int n,         /* input - number of list elements	*/
            int in_value)  /* input - initial value	*/
{

      int i;               /* array subscript and loop control	*/

      for  (i = 0;  i < n;  ++i)
          list[i] = in_value;
}