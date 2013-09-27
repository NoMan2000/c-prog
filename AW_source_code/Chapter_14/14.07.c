Figure 14.7  Allocation of Arrays with calloc
#include <stdlib.h>  /* gives access to calloc */
int scan_planet(planet_t *plnp);
 
int
main(void)
{
      char     *string1;
      int      *array_of_nums;
      planet_t *array_of_planets;
      int       str_siz, num_nums, num_planets, i;

      printf("Enter string length and string> ");
      scanf("%d", &str_siz);
      string1 = (char *)calloc(str_siz, sizeof (char));
      scanf("%s", string1);
 
      printf("\nHow many numbers?> ");
      scanf("%d", &num_nums);
      array_of_nums = (int *)calloc(num_nums, sizeof (int));
      array_of_nums[0] = 5;
      for (i = 1;  i < num_nums;  ++i)
            array_of_nums[i] = array_of_nums[i - 1] * i;
 
      printf("\nEnter number of planets and planet data> ");
      scanf("%d", &num_planets);
      array_of_planets = (planet_t *)calloc(num_planets, 
sizeof (planet_t));
      for (i = 0;  i < num_planets;  ++i)
            scan_planet(&array_of_planets[i]);
      . . .
}
 
Enter string length and string> 9 enormous
 
How many numbers?> 4
  
Enter number of planets and planet data> 2
Earth    12713.5 1  1.0 24.0
Jupiter 142800.0 4 11.9  9.925