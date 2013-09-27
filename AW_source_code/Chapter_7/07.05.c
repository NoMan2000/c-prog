Figure 7.5  Accumulating Weekday Hours Worked
/* Program to demonstrate an enum type loop counter */

#include <stdio.h>

typedef enum
      {monday, tuesday, wednesday, thursday, friday,
       saturday, sunday}
day_t;

void print_day(day_t day);

int
main(void)
{
      double week_hours = 0.0, day_hours;
      day_t today;

      for  (today = monday;  today <= friday;  ++today) {
          printf("Enter hours for ");
          print_day(today);
          printf("> ");
          scanf("%lf", &day_hours);
          week_hours += day_hours;
      }

      printf("\nTotal weekly hours are %.2f\n", week_hours);

      return (0);
}