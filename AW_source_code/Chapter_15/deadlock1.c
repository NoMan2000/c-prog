#include <pthread.h>
#include <stdio.h>

int
main(void)
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    printf("Request 1st Lock\n");
    pthread_mutex_lock(&mutex);
    printf("Granted 1st Lock\n");

    printf("Request 2nd Lock\n");
    pthread_mutex_lock(&mutex);
    printf("Granted 2nd Lock\n");

    return 0;
}
