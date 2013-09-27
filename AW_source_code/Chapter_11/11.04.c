Figure 11.4  Function with a Structured Output Argument
/*
 * Fills a type planet_t structure with input data. Integer returned as 
 * function result is success/failure/EOF indicator.
 *     1 => successful input of one planet
 *     0 => error encountered
 *     EOF => insufficient data before end of file
 * In case of error or EOF, value of type planet_t output argument is 
 * undefined.
 */
int
scan_planet(planet_t *plnp) /* output - address of planet_t structure 
to fill 	*/
{
      int result;
 
      result = scanf("%s%lf%d%lf%lf",  (*plnp).name,
                                       &(*plnp).diameter,
                                       &(*plnp).moons,
                                       &(*plnp).orbit_time,
                                       &(*plnp).rotation_time);
      if (result == 5)
            result = 1;
      else if (result != EOF)
            result = 0;
 
      return (result);
}