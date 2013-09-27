Figure 11.2  Function with a Structured Input Parameter
/*
 * Displays with labels all components of a planet_t structure
 */
void
print_planet(planet_t pl) /* input - one planet structure */
{
      printf("%s\n", pl.name);
      printf("  Equatorial diameter: %.0f km\n", pl.diameter);
      printf("  Number of moons: %d\n", pl.moons);
      printf("  Time to complete one orbit of the sun: %.2f years\n",
pl.orbit_time);
      printf("  Time to complete one rotation on axis: %.4f hours\n",
pl.rotation_time);
}