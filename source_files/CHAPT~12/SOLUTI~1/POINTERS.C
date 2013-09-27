/*
 *      pointers.c
 *
 *      Program to solve exercises 2 and 3, chapter 13 on pointers
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>

/*
 *  print_int_ptr()
 *
 *  Take the address of an integer as a parameter, and print out both the
 *  address and the integer itself
 */
print_int_ptr(int *p)
{
    printf("The address is %d\n", p);
    printf("The value at the address is %d\n", *p);
}

/*
 *  my_scanf()
 *
 *  use scanf to read one integer from the keyboard
 */
my_scanf(int *the_int)
{
    scanf("%d", the_int);
}

main()
{
    int     x;

    printf("Please enter a number: ");
    my_scanf(&x);

    print_int_ptr(&x);

    fflush(stdin);
    getchar();
}

