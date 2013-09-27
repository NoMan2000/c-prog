Figure 6.15  Driver for Function scan_fraction
/* Driver for scan_fraction */

int
main(void)
{
      int num, denom;
      printf("To quit, enter a fraction with a zero numerator\n");
      scan_fraction(&num, &denom);
      while (num != 0) {
            printf("Fraction is %d/%d\n", num, denom);
            scan_fraction(&num, &denom);
      }

      return (0);
}