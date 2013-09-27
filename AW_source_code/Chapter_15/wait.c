/*
 * Create a child process that sleeps for 5 seconds
 * Wait for the child process to exit and retrieve the exit status
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int
main(void)
{
    pid_t pid;  /* Process id  */
    int status; /* Exit status */

    char name[8]; /* Process name */

    /* Create the child process */
    pid = fork();

    if (pid < 0)
    {
        /* Error creating the child process, set the status to 1 */
        strcpy(name, "Failed");
        printf("Failed Fork\n");

        status = 1;
    }
    else if (pid == 0)
    {
        /* Child process, sleep for 5 seconds, set the status to 2 */
        strcpy(name, " Child");
        printf(" Child Process ID %d\n", getpid());

        sleep(5);
        status = 2;
    }
    else
    {
        /* Parent process, wait for the child process, set the status to 3 */
        strcpy(name, "Parent");
        printf("Parent Process ID %d\n", getpid());

        if (wait(&status) == pid)
            printf("Parent Process ID %d Status %d\n",
                    pid, WEXITSTATUS(status)); 
        else
            printf("Failed Wait\n");

        status = 3;
    }

    /* Exit with the status */
    printf("%s Process ID %d Return %d\n", name, getpid(), status);

    return status;
}
