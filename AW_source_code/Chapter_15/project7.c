#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread(void *);

int flag;
pthread_mutex_t mutex;

int
main(void)
{
    pthread_t tid;
    char key;

    flag = 1;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid, NULL, thread, NULL);

    scanf(" %c", &key);

    pthread_mutex_lock(&mutex);
    flag = 0;
    pthread_mutex_unlock(&mutex);

    pthread_join(tid, NULL);

    return 0;
}

void *
thread(void *argument)
{
    int count;
    int local;

    count = 0;

    do
    {
        printf("Count = %d\n", ++count);
        sleep(1);

        pthread_mutex_lock(&mutex);
        local = flag;
        pthread_mutex_unlock(&mutex);
    }
    while (local);

    return NULL;
}
