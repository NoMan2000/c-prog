/* File: thread.c
 * Creates a thread and updates a shared resource from both threads
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int data;              /* Share data */
pthread_mutex_t mutex; /* Mutex lock */

int
main(void)
{
    pthread_t tid; /* Thread ids */
    int loop;      /* Loop count */

    /* Display the primary thread id */
    printf("Thread 1 Started ID 0x%x\n", pthread_self());

    /* Initialize the share data */
    data = 0;

    /* Initialize the mutex lock */
    if (pthread_mutex_init(&mutex, NULL) != 0)
        printf("Error Initializing The Mutex Lock\n");

    /* Create a new thread */
    if (pthread_create(&tid, NULL, thread, NULL) != 0)
        printf("Error Creating The Thread\n");

    /* Wait for the new thread to begin executing */
    sleep(1);

    for (loop = 0; loop < 5; loop++)
    {
        /* Lock the mutex, update the data, unlock the mutex */
        if (pthread_mutex_lock(&mutex) != 0)
            printf("Error Locking Mutex\n");
        printf("Thread 1 Writing Loop %d Data %d\n", loop, ++data);
        if (pthread_mutex_unlock(&mutex) != 0)
            printf("Error Unlocking Mutex\n");

        sleep(1);
    }

    /* Wait for the new thread to finish */
    if (pthread_join(tid, NULL) != 0)
        printf("Failed Join\n");

    printf("Thread 1 Stopped\n");

    return 0;
}

/*
 *  Thread function that runs when the new thread is created
 *  Pre: share data and mutex lock are defined and initialized
 */
void *
thread(void *argument) /* ignored - argument not used */
{
    int loop; /* Loop counter */

    printf("Thread 2 Started ID 0x%x\n", pthread_self());

    /* Wait for the primary thread to write first */
    sleep(1);

    for (loop = 0; loop < 5; loop++)
    {
        /* Lock the mutex, update the data, unlock the mutex */
        if (pthread_mutex_lock(&mutex) != 0)
            printf("Error Locking Mutex\n");
        printf("Thread 2 Writing Loop %d Data %d\n", loop, ++data);
        if (pthread_mutex_unlock(&mutex) != 0)
            printf("Error Unlocking Mutex\n");

        sleep(1);
    }

    printf("Thread 2 Stopped\n");

    return NULL;
}
