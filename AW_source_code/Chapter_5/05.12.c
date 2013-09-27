Figure 5.12  Program to Process Bald Eagle Sightings for a Year
/*
 * Tally by month the bald eagle sightings for the year.  Each month's 
 * sightings are terminated by the sentinel zero.
 */

#include <stdio.h>

#define SENTINEL 0
#define NUM_MONTHS 12

int
main(void)
{
      int month,     /* number of month being processed             */
          mem_sight, /* one member's sightings for this month       */
          sightings; /* total sightings so far for this month       */

      printf("BALD EAGLE SIGHTINGS\n");
      for  (month = 1;
            month <= NUM_MONTHS;
            ++month) {
          sightings = 0;
          scanf("%d", &mem_sight);
          while (mem_sight != SENTINEL) {
             if (mem_sight >= 0)
                 sightings += mem_sight;
             else
                 printf("Warning, negative count %d ignored\n",
                        mem_sight);
             scanf("%d", &mem_sight);
          }  /* inner while */

          printf("  month %2d: %2d\n", month, sightings);
      }   /* outer for */

      return (0);
}

Input data
BALD EAGLE SIGHTINGS
2 1 4 3 0
1 2 0
0
5 4 -1 1 0
. . .

Results
BALD EAGLE SIGHTINGS
  month  1: 10
  month  2:  3
  month  3:  0
Warning, negative count -1 ignored
  month  4: 10
. . .
