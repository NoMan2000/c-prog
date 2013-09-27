/*
 *      arithmetic.c
 *
 *      Program to demonstrate the use of pointer arithmetic
 *
 *      by Mark Virtue, 2001.
 */
#include <stdio.h>
#include <stdlib.h>

static void goodbye()
{
    printf("\nPress ENTER to exit: ");
    fflush(stdin);
    getchar();
}

main()
{
    int     array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int     *ptr = array;
    int     element;

    atexit(goodbye);

    printf("Please enter which element you would like: ");
    scanf("%d", &element);

    printf("\narray[%d] is %d\n", element, array[element]);
    printf("*(array + %d) is %d\n", element, *(array + element));
    printf("ptr[%d] is %d\n", element, ptr[element]);
    printf("*(ptr + %d) is %d\n", element, *(ptr + element));
    printf("\n&(ptr[%d]) is %d\n", element, &(ptr[element]));
    printf("ptr + %d is %d\n", element, ptr + element);

    printf("\nThe ADDRESS difference between element 9 and element 1 is %d\n",
        &(ptr[9]) - &(ptr[1]));

    return 0;
}

