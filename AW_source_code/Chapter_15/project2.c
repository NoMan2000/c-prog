#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int
main(void)
{
    int filedes[2];
    char value[12];

    pipe(filedes);

    if (fork() == 0)
    {
        close(filedes[1]);
         read(filedes[0], value, 12);

        printf("%s\n", value);
    }
    else
    {
        close(filedes[0]);
        write(filedes[1], "Hello World", 11);

        wait(NULL);
    }

    return 0;
}
