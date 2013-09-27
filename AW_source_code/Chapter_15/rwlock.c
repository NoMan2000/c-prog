#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int data;               /* Share data */
pthread_rwlock_t mutex; /* Mutex lock */

int
main(void)
{
    pthread_t tid; /* Created thread id */

    int loop; /* Loop counter */

    printf("Primary Thread Started 0x%x\n", pthread_self());

    /* Initialize the data */
    data = 0;

    /* Initialize the lock */
    if (pthread_rwlock_init(&mutex, NULL) != 0)
        printf("Failed RWLock\n");

    /* Create a new thread */
    if (pthread_create(&tid, NULL, thread, NULL) != 0)
        printf("Failed Thread\n");

    /* Wait for the thread to begin executing */
    sleep(1);

    for (loop = 1; loop <= 5; loop++)
    {
        /* Write lock the rwlock, update the data, unlock the rwlock */
        pthread_rwlock_wrlock(&mutex);
        printf("Primary Thread Writing Loop %d Data %d\n", loop, ++data);
        pthread_rwlock_unlock(&mutex);

        sleep(1);
    }

    /* Wait for the thread to complete */
    if (pthread_join(tid, NULL) != 0)
        printf("Failed Join\n");

    printf("Primary Thread Stopped 0x%x\n", pthread_self());

    return 0;
}

void *
thread(void *argument)
{
    int loop; /* Loop counter */

    printf("Created Thread Started 0x%x\n", pthread_self());

    /* Wait for the primary thread to write first */
    sleep(1);

    for (loop = 1; loop <= 5; loop++)
    {
        /* Read lock the rwlock, display the data, unlock the rwlock */
        pthread_rwlock_rdlock(&mutex);
        printf("Created Thread Reading Loop %d Data %d\n", loop, data);
        pthread_rwlock_unlock(&mutex);

        sleep(1);
    }

    printf("Created Thread Stopped 0x%x\n", pthread_self());

    return NULL;
}
