Figure 11.14  Function That Displays a Structure with a Union Type Component
void
print_hair_info(hair_info_t hair) /* input - structure to display 	*/
{
      if (hair.bald) {
            printf("Subject is bald");
            if (hair.h.wears_wig)
                  printf(", but wears a wig.\n");
            else
                  printf(" and does not wear a wig.\n");
      } else {
            printf("Subject's hair color is %s.\n", hair.h.color);
      }
}