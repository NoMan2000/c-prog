
Figure 15.1  Comparison of C and C++ Control Structures

//
//  Calculates and displays a table showing the safety level of a coffee 
//  room
//

#include <iostream>  // library with I/O operators
#include <iomanip>   // library with output format manipulators
using namespace std;

const double SAFE_RAD = 0.466;   // safe level of radiation
const double SAFETY_FACT = 10.0; // safety factor

int rad_table(double init_radiation, double min_radiation);

int
main()
{
   int    day;             // day user can enter room
   double init_radiation,  // radiation level right after leak
          min_radiation;   // safe level divided by safety factor

   // Compute stopping level of radiation
   min_radiation = SAFE_RAD / SAFETY_FACT;

   // Prompts user to enter initial radiation level
   cout << "Enter the radiation level (in millirems)> ";
   cin >> init_radiation;

   // Displays table
   day = rad_table(init_radiation, min_radiation);

   // Display day the user can enter the room.
   cout << "\nYou can enter the room on day " << day << ".\n";

   return (0);
}

//
// Displays a table showing the radiation level and safety status every 3 
// days until the room is deemed safe to enter.  Returns the day number for
// the first safe day.
//   Pre:  min_radiation and init_radiation are defined.
//   Post: radiation_lev <= min_radiation
//
int
rad_table(double init_radiation, double min_radiation)
{
   int    day;           // days elapsed since substance leak
   double radiation_lev; // current radiation level

   day = 0;
   cout << "\n   Day   Radiation   Status\n        (millirems)\n";
   for  (radiation_lev = init_radiation;
         radiation_lev > min_radiation;
         radiation_lev /= 2.0) {
      if (radiation_lev > SAFE_RAD)
         cout << "  " << setw(3) << day << setw(3) << ' ' <<
            setiosflags(ios::fixed | ios::showpoint) << setprecision(4) <<
            setw(9) << radiation_lev << "    Unsafe\n";
      else
         cout << "  " << setw(3) << day << setw(3) << ' ' <<
            setiosflags(ios::fixed | ios::showpoint) << setprecision(4) <<
            setw(9) << radiation_lev << "    Safe\n";
      day += 3;
   }
   
   return (day);
}

