Figure 11.13  Data File and Sample Run of Measurement Conversion Program
Data file  units.dat:
miles               mi           distance       1609.3 
kilometers          km           distance       1000 
yards               yd           distance       0.9144 
meters              m            distance       1 
quarts              qt           liquid_volume  0.94635
liters              l            liquid_volume  1
gallons             gal          liquid_volume  3.7854
milliliters         ml           liquid_volume  0.001
kilograms           kg           mass           1 
grams               g            mass           0.001 
slugs               slugs        mass           0.14594 

Sample run:
Enter a conversion problem or q to quit.
To convert 25 kilometers to miles, you would enter
> 25 kilometers miles
     or, alternatively,
> 25 km mi
> 450 km miles
Attempting conversion of 450.0000 km to miles . . .
450.0000km  =  279.6247 miles

Enter a conversion problem or q to quit.
> 2.5 qt l
Attempting conversion of 2.5000 qt to l . . .
2.5000qt  =  2.3659 l

Enter a conversion problem or q to quit.
> 100 meters gallons
Attempting conversion of 100.0000 meters to gallons . . .
Cannot convert meters (distance) to gallons (liquid_volume)

Enter a conversion problem or q to quit.
> 1234 mg g
(continued)
Figure 11.13  (continued)
Attempting conversion of 1234.0000 mg to g . . .
Unit mg not in database

Enter a conversion problem or q to quit.
> q