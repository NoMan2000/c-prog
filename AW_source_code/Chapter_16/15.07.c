Figure 15.7  Implementation File for Class Complex
//
//  implementation file complex.cpp
//

#include "complex.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//
// absolute value of a complex number
//
Complex Complex::abs() const
{
   Complex cabs( sqrt(real * real + imag * imag), 0);
   return cabs;
}

//
// sum of current complex number and operand2
//
Complex Complex::operator+ ( Complex operand2 ) const
{
   Complex csum( real + operand2.real, imag + operand2.imag );
   return csum;
}

//
// product of current complex number and operand2
//
Complex Complex::operator* ( Complex operand2 ) const
{
   Complex cproduct( real * operand2.real - imag * operand2.imag,
                     real * operand2.imag + imag * operand2.real );
   return cproduct;
}

//
// difference of current complex number and operand2
//
Complex Complex::operator- ( Complex operand2 ) const
{
   Complex cdiff( real - operand2.real, imag - operand2.imag );
   return cdiff;
}

//
// quotient of current complex number divided by operand2
//
Complex Complex::operator/ ( Complex operand2 ) const
{
   double divisor = operand2.real * operand2.real +
                    operand2.imag * operand2.imag;
   Complex cquot( (real * operand2.real + imag * operand2.imag) / divisor,
                  (imag * operand2.real - real * operand2.imag) / divisor);
   return cquot;
}

//
// Extract from input source the two components of a complex number
//
istream& operator>> (istream& is, Complex& c)
{
   is >> c.real >> c.imag;
   return is;
}

//
// Insert in the output stream a representation of a complex number:
//    either the form (a + bi) or (a - bi), dropping a or b if one of them 
//    rounds to zero
//
ostream& operator<< (ostream& os, Complex c)
{
   double a = c.real;
   double b = c.imag;
   char sign;

   os << setiosflags( ios::fixed | ios::showpoint ) << setprecision(2);
   os << '(';
   if (fabs(a) < .005  && fabs(b) < .005) {
      os << 0.0;
   } else if (fabs(b) < .005) {
      os << a;
   } else if (fabs(a) < .005) {
      os << b;
   } else {
      if (b < 0)
         sign = '-';
      else
         sign = '+';
      os << a << ' ' << sign << ' ' << fabs(b) << 'i';
   }

   os << ')';
   return os;
}

