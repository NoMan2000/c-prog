#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int
main(void)
{
    printf("Parent Started\n");

    if (fork() == 0)
    {
        printf(" Child Started\n");
        sleep(5);
        printf(" Child Finished\n");
    }
    else
    {
        wait(NULL);
        printf("Parent Finished\n");
    }

    return 0;
}
