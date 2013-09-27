Figure 8.7  Function to Find the Largest Element in an Array
/*
 *  Returns the largest of the first n values in array list
 *  Pre:  First n elements of array list are defined and n > 0
 */
int
get_max(const int list[], /* input - list of n integers	*/
	int       n)      /* input - number of list elements to examine	*/
{
      int i,
          cur_large;      /* largest value so far	*/

      /*  Initial array element is largest so far.	*/
      cur_large = list[0];

      /*  Compare each remaining list element to the largest so far;
          save the larger	*/
      for  (i = 1;  i < n;  ++i)
          if (list[i] > cur_large)
                cur_large = list[i];

      return (cur_large);
}