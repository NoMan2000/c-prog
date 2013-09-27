/*
 *  temperature.c
 *
 *  Solution to the Celsius to Fahrenheit exercise from Chapter 3.
 *  Ask for a temperature in degrees Celsius and output the corresponding
 *  Fahrenheit value to two decimal places.
 *
 *  by Mark Virtue, 2001.
 */
#include <stdio.h>

main()
{
    int     celsius;
    double  fahr;

    /*
     *  First, get the Celsius value from the keyboard
     */
    printf("Please enter a temperature in degrees Celsius: ");
    scanf("%d", &celsius);

    /*
     *  Perform the conversion  F = 32 + C * 9/5
     */
    fahr = 32 + (double)celsius * 9 / 5;

    /*
     *  Output the result
     */
    printf("%d degrees Celsius = %.2f degrees Fahrenheit\n",
                        celsius, fahr);

    fflush(stdin);
    getchar();
}

