Figure 15.2   Implementing Output Parameters in C and C++

//
// Separates a number into three parts:  a sign (+, -, 
// blank), a whole number magnitude, and a fractional part.
//
void
separate(double  num,    // input - value to be split       
         char&   sign,   // output - sign of num            
         int&    whole,  // output - whole number magnitude
                                     of num                 
         double& frac)   // output - fractional part of num 
{
    double magnitude;    // magnitude of num                

    // Determines sign of num 
    if (num < 0)
         sign = '-';
    else if (num == 0)
         sign = ' ';
    else
         sign = '+';

    // Finds magnitude of num (its absolute value) and      
    // separates it into whole and fractional parts         
    magnitude = fabs(num);
    whole = floor(magnitude);
    frac = magnitude - whole;
}

