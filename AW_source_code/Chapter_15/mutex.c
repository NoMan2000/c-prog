#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int data;              /* Share data */
pthread_mutex_t mutex; /* Mutex lock */

int
main(void)
{
    pthread_t tid; /* Created thread id */

    int loop; /* Loop counter */

    printf("Primary Thread Started ID 0x%x\n", pthread_self());

    /* Initialize the data */
    data = 0;

    /* Initialize the mutex lock */
    if (pthread_mutex_init(&mutex, NULL) != 0)
        printf("Failed Mutex\n");

    /* Create a new thread */
    if (pthread_create(&tid, NULL, thread, NULL) != 0)
        printf("Failed Thread\n");

    /* Wait for the thread to begin executing */
    sleep(1);

    for (loop = 0; loop < 5; loop++)
    {
        /* Lock the mutex, update the data, unlock the mutex */
        pthread_mutex_lock(&mutex);
        printf("Primary Thread Writing Loop %d Data %d\n", loop, ++data);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    /* Wait for the thread to complete */
    if (pthread_join(tid, NULL) != 0)
        printf("Failed Join\n");

    printf("Primary Thread Stopped ID 0x%x\n", pthread_self());

    return 0;
}

void *
thread(void *argument)
{
    int loop; /* Loop counter */

    printf("Created Thread Started ID 0x%x\n", pthread_self());

    /* Wait for the primary thread to write first */
    sleep(1);

    for (loop = 0; loop < 5; loop++)
    {
        /* Lock the mutex, update the data, unlock the mutex */
        pthread_mutex_lock(&mutex);
        printf("Created Thread Writing Loop %d Data %d\n", loop, ++data);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    printf("Created Thread Stopped ID 0x%x\n", pthread_self());

    return NULL;
}
