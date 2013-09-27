/*
 *      scope2.c
 *
 *      Program to demonstrate the concept of preprocessor directive scope
 *
 *      by Mark Virtue, 2001.
 */
func()
{
    return MAX;
}

#define MAX     10

main()
{
    int x = MAX;
}

