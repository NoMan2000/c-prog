#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

pthread_mutex_t mutexA;
pthread_mutex_t mutexB;

int
main(void)
{
    pthread_t tid;

    pthread_mutex_init(&mutexA, NULL);
    pthread_mutex_init(&mutexB, NULL);

    pthread_create(&tid, NULL, thread, NULL);

    printf("  Main Request mutexA\n");
    pthread_mutex_lock(&mutexA);
    printf("  Main Granted mutexA\n");

    sleep(1);

    printf("  Main Request mutexB\n");
    pthread_mutex_lock(&mutexB);
    printf("  Main Granted mutexB\n");

    pthread_join(tid, NULL);

    return 0;
}

void *
thread(void *argument)
{
    printf("Thread Request mutexB\n");
    pthread_mutex_lock(&mutexB);
    printf("Thread Granted mutexB\n");

    sleep(1);

    printf("Thread Request mutexA\n");
    pthread_mutex_lock(&mutexA);
    printf("Thread Granted mutexA\n");

    return NULL;
}
