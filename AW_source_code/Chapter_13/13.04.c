Figure 13.4  Implementation File planet.c Containing Library with Planet Data 
Type and Operators
/*
 *
 *      planet.c
 */
#include <stdio.h>
#include <string.h>
#include "planet.h"
/*
 *  Displays with labels all components of a planet_t structure
 */
void
print_planet(planet_t pl)  /* input - one planet structure */
{
      printf("  Equatorial diameter: %.0f km\n", pl.diameter);
      printf("  Number of moons: %d\n", pl.moons);
      printf("  Time to complete one orbit of the sun: %.2f years\n",
pl.orbit_time);
      printf("  Time to complete one rotation on axis: %.4f hours\n",
pl.rotation_time);
}
 
/*
 *  Determines whether or not the components of planet_1 and planet_2 match
 */
int
planet_equal(planet_t planet_1,  /* input - planets to                      */ 
             planet_t planet_2)  /*         compare                         */
{
      return (strcmp(planet_1.name, planet_2.name) == 0     &&
              planet_1.diameter == planet_2.diameter        &&
              planet_1.moons == planet_2.moons              &&
              planet_1.orbit_time == planet_2.orbit_time    &&
              planet_1.rotation_time == planet_2.rotation_time);
}

/*
 *  Fills a type planet_t structure with input data.  Integer returned as 
 *  function result is success/failure/EOF indicator.
 *      1 => successful input of planet
 *      0 => error encountered
 *      EOF => insufficient data before end of file
 *  In case of error or EOF, value of type planet_t output argument is 
 *  undefined.
 */
int
scan_planet(planet_t *plnp) /* output - address of planet_t structure to 
fill	*/
{
      int result;

      result = scanf("%s%lf%d%lf%lf",  plnp->name, 
                                       &plnp->diameter,
                                       &plnp->moons, 
                                       &plnp->orbit_time, 
                                       &plnp->rotation_time);
      if (result == 5)
            result = 1;
      else if (result != EOF)
            result = 0;

      return (result);
}