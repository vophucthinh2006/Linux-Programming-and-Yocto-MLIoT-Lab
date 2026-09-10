#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int resource = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void* reader(void* arg) {
    int id = *(int*)arg;

    for (int i = 0; i < 2; i++) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Reader with ID: %d is reading\nResoure: %d\n", id, resource);

        pthread_rwlock_unlock(&rwlock);
        usleep(1000);
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    for (int i = 0; i < 2; i++) {
        pthread_rwlock_wrlock(&rwlock);
        resource++;
        printf("Writer with ID: %d is writing\nResource: %d\n", id, resource);

        pthread_rwlock_unlock(&rwlock);
        usleep(1000);
    }
    return NULL;
}

int main() {
    pthread_t readers[5], writers[2];
    int r_ids[5], w_ids[2];

    //Create 5 reader threads
    for (int i = 0; i < 5; i++) {
        r_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &r_ids[i]);
    }
    
    //Create 2 writers threads
    for (int i = 0; i < 2; i++) {
        w_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &w_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    return 0;
}