#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int
main(void)
{
    pthread_t tid; /* Created thread id */
    int seconds;   /* Seconds counter   */

    printf("Primary Thread Started ID 0x%x\n", pthread_self());

    /* Create a new thread */
    if (pthread_create(&tid, NULL, thread, NULL) != 0)
        printf("Failed Thread\n");

    /* Wait for the thread to begin executing */
    sleep(1);

    for (seconds = 1; seconds <= 5; seconds++)
    {
        /* Print the seconds and sleep for 1 second */
        printf("Primary Thread Seconds %d\n", seconds);
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
    int seconds; /* Seconds counter */

    printf("Created Thread Started ID 0x%x\n", pthread_self());

    /* Wait for the primary thread to write first */
    sleep(1);

    for (seconds = 1; seconds <= 5; seconds++)
    {
        /* Print the seconds and sleep for 1 second */
        printf("Created Thread Seconds %d\n", seconds);
        sleep(1);
    }

    printf("Created Thread Stopped ID 0x%x\n", pthread_self());

    return NULL;
}
