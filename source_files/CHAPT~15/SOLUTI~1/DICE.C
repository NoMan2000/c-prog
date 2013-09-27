/*
 *      dice.c
 *
 *      Program to simulate the rolling of a dice
 *      Chapter 16 exercise 1
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <time.h>

#define SIDES   6       /* sides of a dice */

/*
 *  Macro to convert a random number in the range 0-RAND_MAX
 *  into the range 1-num (e.g. 1-6)
 */
#define rand_range(num, range)  ((num) % (range) + 1)

main()
{
    int     rolls;
    int     i;
    int     number;     /* each random number */

    printf("Please enter the number of rolls you want: ");
    scanf("%d", &rolls);

    srand(time(NULL));

#ifdef NOT_USING_MACRO
    for (i = 0; i < rolls; i++)
    {
        number = rand();
        number = number % SIDES;/* to get it into the range 0-5 */
        number++;               /* to get it into the range 1-6 */
        printf("Roll number %3d produced %d\n", i+1, number);
    }
#else
    for (i = 0; i < rolls; i++)
        printf("MACRO: Roll number %3d produced %d\n",
                         i+1, rand_range(rand(), SIDES));
#endif

    fflush(stdin);
    getchar();

    return 0;       /* no problems */
}

