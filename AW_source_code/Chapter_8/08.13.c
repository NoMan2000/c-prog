Figure 8.13  Driver for Testing fill_to_sentinel
/* Driver to test fill_to_sentinel function */

#define A_SIZE  20
#define SENT   -1.0

int
main(void)
{
      double arr[A_SIZE];
      int    in_use,     /* number of elements of arr in use */
             i;

      fill_to_sentinel(A_SIZE, SENT, arr, &in_use);

      printf("List of data values\n");
      for  (i = 0;  i < in_use;  ++i)
          printf("%13.3f\n", arr[i]);

      return (0);
}