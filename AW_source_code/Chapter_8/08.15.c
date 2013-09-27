Figure 8.15  Function That Searches for a Target Value in an Array
#define NOT_FOUND -1   /* Value returned by search function if target not found 	*/

/*
 *  Searches for target item in first n elements of array arr
 *  Returns index of target or NOT_FOUND
 *  Pre:  target and first n elements of array arr are defined and n>=0
 */
int
search(const int arr[],  /* input - array to search	*/
       int       target, /* input - value searched for	*/
       int       n)      /* input - number of elements to search	*/
{
      int i,
          found = 0,     /*  whether or not target has been found 	*/
          where;         /*  index where target found or NOT_FOUND	*/

      /*  Compares each element to target	*/
      i = 0;
      while (!found && i < n) {
          if (arr[i] == target)
                found = 1;
          else
                ++i;
      }

      /* Returns index of element matching target or NOT_FOUND	*/
      if (found)
            where = i;
      else
            where = NOT_FOUND;

      return (where);
}
