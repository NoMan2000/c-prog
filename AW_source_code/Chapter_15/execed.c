#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    pid_t tpid; /* This process id */

    /* Get the process id for this process */
    tpid = getpid();

    printf(" Child Started Process ID %d\n", tpid);
    sleep(5);
    printf(" Child Stopped Process ID %d\n", tpid);

    return 0;
}
