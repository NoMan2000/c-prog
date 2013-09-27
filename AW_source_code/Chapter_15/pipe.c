#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MESSAGE "Parent Message To Child"
#define SIZE sizeof(MESSAGE)

int global; /* Global variable */

int
main(void)
{
    int local; /* Local variable */

    int filedes[2]; /* Process pipe */

    pid_t fpid; /* Fork process id */
    pid_t tpid; /* This process id */

    char name[8];      /* Process name */
    char text[SIZE+1]; /* Process text */

    printf("Launch Program\n");

    /* Initialize the global and local variables */
    global = 1;
    local  = 2;

    /* Create the interprocess communications pipe */
    if (pipe(filedes) < 0)
    {
        /* The pipe failed */
        strcpy(name, "Failed");
        printf("Failed Pipe\n");
    }
    else
    {
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

            /* Close the write pipe */
            close(filedes[1]);

            /* Read from the pipe */
            read(filedes[0], text, SIZE);
            printf(" Child Reading %s\n", text);

            /* Change the global and local variables */
            global = 3;
            local  = 4;
        }
        else
        {
            /* In the parent process */
            strcpy(name, "Parent");
            printf("Parent Started Process ID %d\n", tpid);

            /* Close the read pipe */
            close(filedes[0]);

            /* Wait for the child to begin executing */
            sleep(1);

            /* Write to the pipe */
            printf("Parent Writing %s\n", MESSAGE);
            write(filedes[1], MESSAGE, SIZE);

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
    }

    printf("%s Stopped Process ID %d Global %d Local %d\n",
            name, tpid, global, local);

    return 0;
}
