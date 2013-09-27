/*
 *      static2.c
 *
 *      The second of two files used to answer the chapter 14
 *      exercise on two functions with identical names
 *
 *      by Mark Virtue, 2001.
 */
static int  count;

static initialise()
{
    count = 200;
}

func()
{
    initialise();
}

