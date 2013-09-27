/*
 * File: parent.c
 * Creates a child process, replaces the child process image with a 
 * new process image from the executable file, communicates using a 
 * pipe and retrieves the status returned from the child process
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

/* Define the message to be sent using the pipe */
#define MESSAGE "Parent Message To Child Process"

int
main(void)
{
    int filedes[2]; /* Pipe file descriptors */

    pid_t cpid; /* Child process id     */
    int status; /* Child process status */

    printf("Launch Program\n");

    /* Create the pipe */
    if (pipe(filedes) < 0)
        printf("Error Creating The Pipe\n");

    /* Create a child process */ 
    cpid = fork();

    /* Both the parent process and child process continue here */
    if (cpid < 0)
    {
        /* The child process was not created */
        printf("Error Creating The Child Process\n");

        /* Close the read and write file descriptors */
        if (close(filedes[0]) != 0)
            printf("Error Closing File Descriptor 0\n");
        if (close(filedes[1]) != 0)
            printf("Error Closing File Descriptor 1\n");
    }
    else if (cpid == 0)
    {
        /* This is the child process */
        printf(" execl Process ID %d\n", getpid());

        /* Close the write file descriptor */
        if (close(filedes[1]) != 0)
            printf("Error Closing File Descriptor 0\n");

        /* Duplicate and assign the read file descriptor to *
         * standard input                                   */
        if (dup2(filedes[0], STDIN_FILENO) != STDIN_FILENO)
            printf("Error Duplicating File Descriptor 0\n");

        /* Close the read file descriptor after duplication */
        if (close(filedes[0]) != 0)
            printf("Error Closing File Descriptor 0\n");

        /* Replace this process image with the process *
         * image from the executable file child.exe    */
        if (execl("child.exe", "child.exe", NULL) < 0)
            printf("Error Replacing This Process Image\n");
    }
    else
    {
        /* This is the parent process */
        printf("Parent Process ID %d\n", getpid());

        /* Close the read file descriptor */
        if (close(filedes[0]) != 0)
            printf("Error Closing Pipe\n");

        /* Wait for the child process to begin executing */
        sleep(1);

        printf("Parent Process Writing %s\n", MESSAGE);

        /* Write the message to the write file descriptor and flush *
         * the write file descriptor by writing a newline character */
        if (write(filedes[1], MESSAGE, sizeof(MESSAGE)) < 0)
            printf("Error Writing To File Descriptor 1\n");
        if (write(filedes[1], "\n", 1) < 0)
            printf("Error Writing To File Descriptor 1\n");

        printf("Parent Process Waiting For Child Process\n");

        /* Wait for the child process and display the status */
        if (wait(&status) != cpid)
            printf("Error Waiting For The Child Process\n");

        printf("Parent Process Resumed\n");
        printf("Parent Process Receive Status %d From Child\n",
                WEXITSTATUS(status));
    }

    printf("Parent Process Exiting\n");

    return 0;
}
