#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int data = 0;
int data_ready = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    (void)arg; // Unused parameter

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        // Wait until the consumer has consumed the previous data
        while (data_ready == 1) {
            pthread_cond_wait(&cond, &mutex);
        }

        data = rand() % 100; // Produce some data
        data_ready = 1;
        printf("Produced: %d\n", data);

        //Signal the consumer that data is ready
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* arg) {
    (void) arg; // Unused parameter

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);

        // Wait until the producer has produced new data
        while (data_ready == 0) {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("Consumed: %d\n", data);
        data_ready = 0;

        // Signal the producer that data has been consumed
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}