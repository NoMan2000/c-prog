#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int global; /* Global variable */

int
main(void)
{
    int local; /* Local variable */

    int filedes[2]; /* Process pipe */

    pid_t fpid; /* Fork process id */
    pid_t tpid; /* This process id */

    char name[8]; /* Process name */

    printf("Launch Program\n");

    /* Initialize the global and local variables */
    global = 1;
    local  = 2;

    /* Create the read and write pipes */
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
            printf(" Child execl   Process ID %d\n", tpid);

            /* Close the write pipe */
            close(filedes[1]);

            if (filedes[0] != STDIN_FILENO)
            {
                /* Set the standard input to the read pipe */
                if (dup2(filedes[0], STDIN_FILENO) != STDIN_FILENO)
                {
                    /* The dup2 failed */
                    strcpy(name, "Failed");
                    printf("Failed Dup2\n");
                }

                /* Close the read pipe */
                close(filedes[0]);
            }

            /* Replace this process with the execl program */
            if (execl("dup2ed.exe", "dup2ed.exe", NULL) < 0)
            {
                /* The execl failed */
                strcpy(name, "Failed");
                printf("Failed execl\n");
            }

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
            printf("Parent Writing Parent Message To Child\n");
            write(filedes[1], "Parent Message To Child\n", 24);

            printf("Parent Waiting Process ID %d\n", tpid);

            /* Wait for the child process to complete */
            if (waitpid(fpid, NULL, 0) != fpid)
            {
                /* Failed Wait */
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
