/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "mutex.h"

#define NUM_CHILDREN 2

void perror_exit(char *s)
{
    perror(s);
    exit(-1);
}

void *check_malloc(int size)
{
    void *p = malloc(size);
    if (p == NULL) {
        perror_exit("malloc failed");
    }
    return p;
}

typedef struct {
    int counter;
    int end;
    Mutex *mutex;
} Shared;

Shared *make_shared(int end)
{
    int i;
    Shared *shared = check_malloc(sizeof(Shared));

    shared->counter = 0;
    shared->end = end;

    shared->mutex = make_mutex();
    return shared;
}

pthread_t make_thread(void *(*entry)(void *), Shared *shared)
{
    int ret;
    pthread_t thread;

    ret = pthread_create(&thread, NULL, entry, (void *) shared);
    if (ret != 0) {
        perror_exit("pthread_create failed");
    }
    return thread;
}

void join_thread(pthread_t thread)
{
    int ret = pthread_join(thread, NULL);
    if (ret == -1) {
        perror_exit("pthread_join failed");
    }
}

void child_code(Shared *shared)
{
    printf("Starting child at counter %d\n", shared->counter);

    while (1) {
        if (shared->counter >= shared->end) {
            return;
        }
	mutex_lock(shared->mutex);
        shared->counter++;
	mutex_unlock(shared->mutex);
        /*if (shared->counter % 10000 == 0) {
            printf("%d\n", shared->counter);
	    }*/
    }
}

void *entry(void *arg)
{
    Shared *shared = (Shared *) arg;
    child_code(shared);
    printf("Child done.\n");
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t child[NUM_CHILDREN];

    Shared *shared = make_shared(1000000);

    for (i=0; i<NUM_CHILDREN; i++) {
        child[i] = make_thread(entry, shared);
    }

    for (i=0; i<NUM_CHILDREN; i++) {
        join_thread(child[i]);
    }

    //check_array(shared);
    return 0;
}
