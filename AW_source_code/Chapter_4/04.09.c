Figure 4.9  Function comp_use_charge Revised
/*
 * Computes use charge with conservation requirements
 * Pre: previous, current, and use_last_year are defined.
 */
double
comp_use_charge(int previous, int current, int use_last_year)
{
      int used;  /* gallons of water used (in thousands)	*/
      double use_charge;  /* charge for actual water use 	*/
      
      used = current - previous;
      if (used <= CONSERV_RATE / 100.0 * use_last_year) {
            /* conservation guidelines met */ 
            use_charge = used * PER_1000_CHG;
      } else {
            printf("Use charge is at %.2f times ", OVERUSE_CHG_RATE);
            printf("normal rate since use of\n");
            printf("%d units exceeds %d percent ", used, CONSERV_RATE);
            printf("of last year's %d-unit use.\n", use_last_year);
            use_charge = used * OVERUSE_CHG_RATE * PER_1000_CHG;
      }

      return (use_charge);
}