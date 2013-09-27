/*
 * File: child.c
 * Reads a newline delimited string from the standard input,
 * prints the string to the standard output and returns 1 to
 * the parent process
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
    char text[64]; /* Message buffer */

    /* Display the child process ID */
    printf(" Child Process ID %d\n", getpid());

    /* Read a newline delimited string from the standard input */
    if (fgets(text, sizeof(text)-1, stdin) == NULL)
        printf("Error Reading Standard Input\n");

    /* Display the message read from standard input */
    printf(" Child Process Reading %s\n", text);
    printf(" Child Process Exiting With Status 1\n");

    /* Return 1 to the parent process */
    return 1;
}
