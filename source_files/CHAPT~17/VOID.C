/*
 *      void.c
 *
 *      Program to demonstrate the use of a void pointer
 *
 *      by Mark Virtue, 2001.
 */
#include <stdlib.h>
#include <memory.h>

/*
 *  memdup()
 *
 *  A function that takes a pointer to any type of memory,
 *  then creates a duplicate amount of memory (using malloc)
 *  and copies the original memory into the new memory
 */
void *memdup(void *mem, int size)
{
    void    *newptr;

    newptr = malloc(size);
    memcpy(newptr, mem, size);
    return newptr;

/* could be written:   return memcpy(malloc(size), mem, size);  */
}

main()
{
    float   float_array1[] = {1.2, 2.3, 3.4};
    int     int_array1[] = {1, 2, 3, 4, 5, 6};
    char    char_array1[] = "Hello World\n";
    float   *float_array2;
    int     *int_array2;
    char    *char_array2;

    float_array2 = memdup(float_array1, sizeof float_array1);
    int_array2 = memdup(int_array1, sizeof int_array1);
    char_array2 = memdup(char_array1, sizeof char_array1);

    free(float_array2);
    free(int_array2);
    free(char_array2);

    return 0;
}

