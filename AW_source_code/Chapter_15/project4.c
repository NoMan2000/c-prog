#include <unistd.h>
#include <wait.h>

int
main(void)
{
    int filedes[2];

    pipe(filedes);

    if (fork() == 0)
    {
        dup2(filedes[0], STDIN_FILENO);

        close(filedes[1]);
        close(filedes[0]);

        execl("child.exe", "child.exe", NULL);
    }
    else
    {
        close(filedes[0]);
        write(filedes[1], "Hello World\n", 12);

        wait(NULL);
    }

    return 0;
}
