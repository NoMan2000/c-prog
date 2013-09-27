#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int data;
pthread_mutex_t mutex;

int
main(void)
{
    pthread_t tid;

    data = 0;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid, NULL, thread, NULL);

    pthread_mutex_lock(&mutex);
    printf("Main Thread Data = %d\n", ++data);
    pthread_mutex_unlock(&mutex);

    pthread_join(tid, NULL);

    return 0;
}

void *
thread(void *argument)
{
    pthread_mutex_lock(&mutex);
    printf(" New Thread Data = %d\n", ++data);
    pthread_mutex_unlock(&mutex);

    return NULL;
}
