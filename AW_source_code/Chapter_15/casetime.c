/*
 * File: casetime.c
 * Models the delivery and dispensing of gasoline
 */

#include <pthread.h>
#include <stdio.h>
#include <wait.h>

int get_number(void);
int get_amount(void);

void startup(int *number, pthread_t *ptid);
void cleanup(pthread_t ptid);

void *producer(void *argument);
void *consumer(void *argument);

#define CAPACITY 1000 /* Storage tank refill capacity */
#define INTERVAL   50 /* Storage tank refill interval */

#define FILL_RATE 50 /* Storage tank fill rate */
#define FLOW_RATE  5 /* Station pump flow rate */

#define PUMPS 10 /* Number of pumps available */

#define VERBOSE 0 /* Verbose display off (0) */

int canceled; /* Producer thread canceled (1) or not (0) */

int inventory;   /* Storage tank inventory */
int pump[PUMPS]; /* Pump quantity requests */

pthread_mutex_t mutex; /* Mutual exclusion lock */

int
main(void)
{
    int number; /* Pump number */

    pthread_t ptid; /* Producer thread id */
    pthread_t ctid; /* Consumer thread id */

    /* Startup the application */
    startup(&number, &ptid);

    /* Loop until the user sets the pump number to -1 */
    while (number != -1)
    {
        /* Get the pump number */
        number = get_number();

        if (number != -1)
        {
            if (pthread_mutex_lock(&mutex) != 0)
                printf("Error Locking Mutex\n");

            /* Assign the amount to the pump */
            pump[number-1] = get_amount();

            if (pthread_mutex_unlock(&mutex) != 0)
                printf("Error Unlocking Mutex\n");

            /* Create a new consumer thread passing in the pump number */ 
            if (pthread_create(&ctid, NULL, consumer, &number) != 0)
                printf("Error Creating The Consumer Thread\n");
        }
    }

    /* Cleanup the application */
    cleanup(ptid);

    return 0;
}

/*
 *  Initialize the global parameters and start the producer thread
 *  Pre:  parameters are defined and contain valid memory addresses,
 *        global parameters are defined
 *  Post: global parameters are initialized, *ptid is modified and
 *        contains the producer thread id, *number is modified and
 *        contains 0 if successful or -1 if unsuccessful
 */
void
startup(int       *number, /* output - initial pump number */
        pthread_t *ptid)   /* output - producer thread id  */
{
    int count; /* Loop counter */

    /* Initialize the producer thread canceled flag to 0 */
    canceled = 0;

    /* Initialize the storage tank inventory to the CAPACITY */
    inventory = CAPACITY;

    /* Initialize all pump amounts to 0 */
    for (count = 0; count < PUMPS; count++)
        pump[count] = 0;

    /* Initialize the pump number */
    *number = 0;

    /* Initialize the mutex lock and create the producer thread *
     * Set the pump number to -1 if either of these fail since  *
     * the application can't continue                           */
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Error Initializing The Mutex Lock\n");
       *number = -1;
    }
    else if (pthread_create(ptid, NULL, producer, NULL) != 0)
    {
        printf("Error Creating The Producer Thread\n");
       *number = -1;
    }
}

/*
 *  Check for active consumer threads, wait for all active consumer
 *  threads to finish and cancel the producer thread
 *  Pre: ptid is defined
 */
void
cleanup(pthread_t ptid) /* Input - producer thread id to cancel */
{
    int checks; /* Pump checks */
    int number; /* Pump number */
    int active; /* Pump active */

    /* Initialize the pump checks counter */
    checks = 0;

    do
    {
        /* Initialize the pump number and active flag to 0 */
        number = 0;
        active = 0;

        while (number < PUMPS && !active)
        {
            if (pthread_mutex_lock(&mutex) != 0)
                printf("Error Locking Mutex\n");

            /* Look for pumps that are active */
            if (pump[number] > 0)
                active = 1;
            else
                number++;

            if (pthread_mutex_unlock(&mutex) != 0)
                printf("Error Unlocking Mutex\n");
        }

        if (active)
        {
            /* Increment the checks counter */
            checks++;

            /* Display the active pumps message on the first check */
            if (checks == 1)
                printf("Wait For Active Pump(s) To Finish\n");

            /* Sleep for one second before checking again */
            sleep(1);
        }
    }
    while (active);

    if (pthread_mutex_lock(&mutex) != 0)
        printf("Error Locking Mutex\n");

    /* Set the producer thread canceled flag to 1 */
    canceled = 1;

    if (pthread_mutex_unlock(&mutex) != 0)
        printf("Error Unlocking Mutex\n");
    
    /* Wait for the producer thread to finish */
    if (pthread_join(ptid, NULL) != 0)
        printf("Error Joining The Producer Thread\n");
}

/*
 *  Return the selected pump number to activate
 */
int
get_number(void)
{
    int number; /* Pump number */

    do
    {
        /* Get the pump number */
        printf("Enter A Pump Number From 1 To %d or -1 To Quit\n", PUMPS);
        scanf(" %d", &number);

        /* Skip processing if the pump number is -1 */
        if (number != -1)

            /* Validate the pump number */
            if (number < 1 || number > PUMPS)
            {
                printf("The Pump Number Must Be From 1 To %d\n", PUMPS);
                number = 0;
            }
            else
            {
                if (pthread_mutex_lock(&mutex) != 0)
                    printf("Error Locking Mutex\n");

                /* Check to see if the pump is available */
                if (pump[number-1] > 0)
                {
                    printf("Pump Number %d Is Already In Use\n", number);
                    number = 0;
                }

                if (pthread_mutex_unlock(&mutex) != 0)
                    printf("Error Unlocking Mutex\n");
            }
    }
    while (number == 0);

    return number;
}

/*
 *  Return the selected amount of gasoline to pump
 */
int
get_amount(void)
{
    int amount; /* Pump amount */

    do
    {
        /* Get the amount of gasoline to pump */
        printf("Enter The Amount Of Gasoline To Pump\n");
        scanf(" %d", &amount);

        /* Validate the amount of gasoline */
        if (amount <= 0)
        {
            printf("The Amount Of Gasoline Must Be Greater Than 0\n");
            amount = 0;
        }
    }
    while (amount == 0);

    return amount;
}

/*
 *  Producer thread function that runs until the canceled flag is 1
 *  Pre: global parameters are defined and have been initialized
 */
void *
producer(void *argument) /* ignored - argument is not used */
{
    int elapse; /* Elapsed seconds   */
    int cancel; /* Local cancel flag */
    int number; /* Pump number count */
    int remain; /* Pump remain count */

    /* Initialize the elapsed seconds */
    elapse = 0;

    /* Loop until the local cancel flag is set to 1 */
    do
    {
        /* Increment the elapsed seconds */
        elapse++;

        if (pthread_mutex_lock(&mutex) != 0)
            printf("Error Locking Mutex\n");

        /* Refill the storage tank after INTERVAL seconds has elapsed */
        if (elapse >= INTERVAL)
        {
            /* Reset the elapsed seconds */
            elapse = 0;

            /* Refill the storage tank if inventory is below CAPACITY */
            if (inventory < CAPACITY)
            {
                printf("Taking Pump(s) Off Line\n");

                /* Consumer threads are blocked */
                for (number = 1; number <= PUMPS; number++)
                    if (pump[number-1] > 0)
                        printf("Pump Number %d Off Line\n", number);

                printf("Storage Tank Refill Started Inventory %d\n",
                       inventory);

                /* Refill the storage tank at FILL_RATE gallons *
                 * per second                                   */
                while (inventory < CAPACITY)
                {
                    /* Do not refill the storage tank beyond CAPACITY */
                    if (inventory + FILL_RATE <= CAPACITY)
                        inventory += FILL_RATE;
                    else
                        inventory = CAPACITY;

                    if (VERBOSE)
                        printf("Storage Tank Inventory %d\n", inventory);

                    /* Sleep for one second before checking again */
                    sleep(1);
                }

                printf("Storage Tank Refill Finished Inventory %d\n",
                        inventory);
                printf("Putting Pump(s) Back On Line\n");

                /* Consumer threads are unblocked */ 
                for (number = 1; number <= PUMPS; number++)
                {
                    remain = pump[number-1];

                    if (remain > 0)
                        printf("Pump Number %d On Line %d Remain\n",
                                number, remain);
                }
            }
        }

        /* Assign the global canceled flag to the local cancel *
         * flag for use in the while condition after the mutex *
         * has been unlocked                                   */
        cancel = canceled;

        if (pthread_mutex_unlock(&mutex) != 0)
            printf("Error Unlocking Mutex\n");

        /* Sleep for one second before checking again */
        sleep(1);
    }
    while (!cancel);

    printf("Storage Tank Deliveries Canceled\n");

    return NULL;
}

/*
 *  Consumer thread function that runs for each pump request until
 *  the pump request has been satisfied, each consumer thread runs
 *  its own copy of the consumer thread function
 *  Pre: global parameters are defined and have been initialized
 */
void *
consumer(void *argument) /* input - pump number to activate */
{
    int number; /* Pump number */
    int output; /* Pump output */
    int amount; /* Pump amount */

    /* Cast argument as an int* and assign the contents to number */
    number = *(int*) argument;

    /* Initialize the output */
    output = 0;

    printf("Pump Number %d Started\n", number);

    do
    {
        if (pthread_mutex_lock(&mutex) != 0)
            printf("Error Locking Mutex\n");

        /* Do not dispense more gasoline than requested */
        if (pump[number-1] < FLOW_RATE)
            amount = pump[number-1];
        else
            amount = FLOW_RATE;

        /* Do not dispense more gasoline than is available */
        if (amount > inventory)
            amount = inventory;

        /* Reduce the storage tank inventory and pump by the amount */
        inventory -= amount;
        pump[number-1] -= amount;

        /* Increment the output by the amount */
        output += amount;

        /* Store the remaining pump amount in the local variable *
         * amount for use in the while condition after the mutex *
         * has been unlocked                                     */
        amount = pump[number-1];

        if (VERBOSE)
            printf("Pump Number %d Output %d\n", number, output);

        if (pthread_mutex_unlock(&mutex) != 0)
            printf("Error Unlocking Mutex\n");

        /* Sleep for one second before checking again */
        sleep(1);
    }
    while (amount > 0);

    printf("Pump Number %d Finished Output %d\n", number, output);

    return NULL;
}
