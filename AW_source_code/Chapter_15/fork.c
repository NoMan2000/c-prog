#include <stdio.h>
#include <string.h>
#include <unistd.h>

int global; /* Global variable */

int
main(void)
{
    int local; /* Local variable */

    pid_t fpid; /* Fork process id */
    pid_t tpid; /* This process id */

    char name[8]; /* Process name */

    printf("Launch Program\n");

    /* Initialize the global and local variables */
    global = 1;
    local  = 2;

    /* Fork a new process */
    fpid = fork();

    /* Get the process id for this process */
    tpid = getpid();

    if (fpid < 0)
    {
        /* The fork failed */
        strcpy(name, "Failed");
        printf("Failed Fork\n");
    }
    else if (fpid == 0)
    {
        /* In the child process */
        strcpy(name, " Child");
        printf(" Child Started Process ID %d\n", tpid);

        /* Change the global and local variables */
        global = 3;
        local  = 4;
    }
    else
    {
        /* In the parent process */
        strcpy(name, "Parent");
        printf("Parent Started Process ID %d\n", tpid);
    }

    printf("%s Stopped Process ID %d Global %d Local %d\n",
            name, tpid, global, local);

    return 0;
}
