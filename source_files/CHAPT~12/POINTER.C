/*
 *      pointer.c
 *
 *      Program to demonstrate the correct use of pointers
 *
 *      by Mark Virtue, 2001.
 */
main()
{
    int     x;
    int     *ptr;

    /*
     *  Which of the following statements is a legal and meaningful
     *  first step that this program could carry out?
     */
    *ptr = x;   /* LEGAL, but unwise - ptr is not initialised */
    &ptr = x;   /* ILLEGAL - attempting to move ptr in memory */
    ptr = &x;   /* LEGAL and MEANINGFUL - initialise ptr */
    ptr = *x;   /* ILLEGAL - x is not a pointer, it can't point to anything */
}

