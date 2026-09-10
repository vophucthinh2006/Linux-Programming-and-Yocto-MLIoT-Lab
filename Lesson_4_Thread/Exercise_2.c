#include <stdio.h>
#include <pthread.h>

long long counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* increment_counter(void* arg) {
    (void)arg; // Unused parameter

    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, increment_counter,NULL);
    pthread_create(&t2, NULL, increment_counter,NULL);
    pthread_create(&t3, NULL, increment_counter,NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Final counter value: %lld\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}

/*
REPORT SECTION:

    Mutex is used in this code to ensure that only one thread can access the shared variable 'counter' at a time.
This prevents race conditions and ensures data integrity.

    If we remove the mutex lock and unlock calls, multiple threads could increment the counter simultaneously,
leading to incorrect final values due to race conditions
*/