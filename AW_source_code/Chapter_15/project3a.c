#include <stdio.h>
#include <unistd.h>

int
main(void)
{
    printf(" Child Started\n");
    sleep(5);
    printf(" Child Finished\n");

    return 0;
}
