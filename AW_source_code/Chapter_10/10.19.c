Figure 10.19  Recursive Selection Sort
/*
 *  Finds the largest value in list array[0]..array[n-1] and exchanges it 
 *  with the value at array[n-1]
 *  Pre:  n > 0 and first n elements of array are defined
 *  Post: array[n-1] contains largest value
 */
void
place_largest(int array[],   /* input/output - array in which to place largest 	*/
              int n)         /* input - number of array elements to 
consider   	*/
{
      int temp,       /* temporary variable for exchange	*/
          j,          /* array subscript and loop control 	*/
          max_index;  /* index of largest so far 	*/

      /*  Save subscript of largest array value in max_index	*/
      max_index = n - 1;     /* assume last value is largest	*/
      for  (j = n - 2;  j >= 0;  --j)
          if (array[j] > array[max_index])
                max_index = j;

      /*  Unless largest value is already in last element, exchange 
largest and last elements	*/
      if (max_index != n - 1) {
            temp = array[n - 1];
            array[n - 1] = array[max_index];
            array[max_index] = temp;
      }
}

/*
 *  Sorts n elements of an array of integers
 *  Pre:  n > 0 and first n elements of array are defined
 *  Post: array elements are in ascending order
 */
void
select_sort(int array[],  /* input/output - array to sort 	*/
            int n)        /* input - number of array elements to sort	*/
{   
      if (n > 1) {
            place_largest(array, n);
            select_sort(array, n - 1);
      }
}