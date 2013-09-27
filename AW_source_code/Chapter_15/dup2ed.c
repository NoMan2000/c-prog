#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    pid_t tpid;    /* This process id */
    char text[32]; /* Read buffer     */

    /* Get the process id for this process */
    tpid = getpid();

    printf(" Child Started Process ID %d\n", tpid);

    /* Read from the standard input */
    fgets(text, sizeof(text), stdin);

    printf(" Child Reading %s", text);
    printf(" Child Stopped Process ID %d\n", tpid);

    return 0;
}
