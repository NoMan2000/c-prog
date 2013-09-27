#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int
main(void)
{
    pthread_t tid;

    printf("Main Thread Started\n");

    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL);

    printf("Main Thread Finished\n");

    return 0;
}

void *
thread(void *argument)
{
    printf(" New Thread Started\n");
    sleep(5);
    printf(" New Thread Finished\n");

    return NULL;
}
