Figure 15.6  Header File for Class Complex

//
//  header file complex.h
//
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex {

public:
   // Constructors
   Complex() { real = 0; imag = 0; }  // default constructor
   Complex(double rl) { real = rl; imag = 0; }  // constructor that
                                 // converts reals to complex numbers
   Complex(double rl, double im) { real = rl; imag = im; } // constructor
                       // with 2 parameters corresponding to 2 data members

   // Member function
   Complex abs() const;

   // Member operators
   Complex operator+ (Complex operand2) const;
   Complex operator- (Complex operand2) const;
   Complex operator* (Complex operand2) const;
   Complex operator/ (Complex operand2) const;

private:
   // Data members
   double real;  // real and imaginary parts
   double imag;  //   of a complex number

   // I/O operators
friend istream& operator>> (istream& is, Complex& innum);
friend ostream& operator<< (ostream& os, Complex outnum);
};

#endif
