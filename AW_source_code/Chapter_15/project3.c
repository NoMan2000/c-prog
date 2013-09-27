#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int
main(void)
{
    printf("Parent Started\n");

    if (fork() == 0)
    {
        execl("child.exe", "child.exe", NULL);
    }
    else
    {
        wait(NULL);
        printf("Parent Finished\n");
    }

    return 0;
}
