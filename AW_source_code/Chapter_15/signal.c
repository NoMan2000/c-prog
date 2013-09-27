#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

void handler(int);

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

        /* Set the handler for the SIGUSR1 signal */
        if (signal(SIGUSR1, handler) == SIG_ERR)
            printf("Failed Signal\n");

        /* Wait for the SIGUSR1 Signal */
        sleep(5);

        /* Change the global and local variables */
        global = 3;
        local  = 4;
    }
    else
    {
        /* In the parent process */
        strcpy(name, "Parent");
        printf("Parent Started Process ID %d\n", tpid);

        /* Wait for the child to begin executing */
        sleep(1);

        printf("Parent Signals SIGUSR1\n");

        /* Send the SIGUSR1 Signal to the child */
        if (kill(fpid, SIGUSR1) < 0)
        {
            /* The kill failed */
            strcpy(name, "Failed");
            printf("Failed Kill\n");
        }

        printf("Parent Waiting Process ID %d\n", tpid);

        /* Wait for the child process to complete */
        if (waitpid(fpid, NULL, 0) != fpid)
        {
            /* The wait failed */
            strcpy(name, "Failed");
            printf("Failed Wait\n");
        }

        printf("Parent Resumed Process ID %d\n", tpid);
    }

    printf("%s Stopped Process ID %d Global %d Local %d\n",
            name, tpid, global, local);

    return 0;
}

void
handler(int signo)
{
    /* Reset the handler for the SIGUSR1 signal */
    if (signal(SIGUSR1, handler) == SIG_ERR)
        printf("Failed Signal\n");

    printf(" Child Receive SIGUSR1\n");
}

