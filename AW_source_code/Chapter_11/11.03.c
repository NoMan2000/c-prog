Figure 11.3  Function Comparing Two Structured Values for Equality
#include <string.h>

/*
 * Determines whether or not the components of planet_1 and planet_2 match
 */
int
planet_equal(planet_t planet_1, /* input - planets to           */
             planet_t planet_2) /*         compare              */
{
      return (strcmp(planet_1.name, planet_2.name) == 0       &&
              planet_1.diameter == planet_2.diameter        &&
              planet_1.moons == planet_2.moons              &&
              planet_1.orbit_time == planet_2.orbit_time    &&
              planet_1.rotation_time == planet_2.rotation_time);
}