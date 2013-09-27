Figure 14.6  Referencing Components of a Dynamically Allocated Structure
printf("%s\n", planetp->name);
printf("  Equatorial diameter:  %.0f km\n", planetp->diameter);
printf("  Number of moons:  %d\n", planetp->moons);
printf("  Time to complete one orbit of the sun:  %.2f years\n",
planetp->orbit_time);
printf("  Time to complete one rotation on axis:  %.4f hours\n",
planetp->rotation_time);