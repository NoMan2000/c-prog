#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int
main(void)
{
    pthread_t tid;
    int arg;

    arg = 10;

    pthread_create(&tid, NULL, thread, &arg);
    pthread_join(tid, NULL);

    return 0;
}

void *
thread(void *argument)
{
    printf("New Thread Argument = %d\n", *(int*) argument);
    return NULL;
}
