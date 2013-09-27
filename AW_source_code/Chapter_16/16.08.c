Figure 15.8  Driver Function  to Test Class Complex
//
// Driver for Complex -- equivalent to driver of Fig. 11.10
//

#include "complex.h"


int
main()
{
   Complex com1, com2;
 
   // Gets two complex numbers
   cout << "Enter the real and imaginary parts of a complex number\n";
   cout << "separated by a space> ";
   cin >> com1;
   cout << "Enter a second complex number> ";
   cin >> com2;

   // Forms and displays the sum
   cout << "\n" << com1 << "  +  " << com2 << "  =  " << (com1 + com2);

   // Forms and displays the difference
   cout << "\n\n" << com1 << "  -  " << com2 << "  =  " << (com1 - com2);

   //Forms and displays the absolute value of the first number
   cout << "\n\n|" << com1 << "| = " << com1.abs() << "\n";

   return (0);
}
