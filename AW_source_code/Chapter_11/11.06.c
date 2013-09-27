Figure 11.6  Function get_planet Returning a Structured Result Type
/*
 * Gets and returns a planet_t structure
 */
planet_t
get_planet(void)
{
      planet_t planet;

      scanf("%s%lf%d%lf%lf",  planet.name,
                              &planet.diameter,
                              &planet.moons,
                              &planet.orbit_time,
                              &planet.rotation_time);
      return (planet);
}