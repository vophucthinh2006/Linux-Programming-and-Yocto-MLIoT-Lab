#include <stdio.h>
#include <pthread.h>

void* thread_routine(void* arg) {
    (void)arg; // Unused parameter

    pthread_t id = pthread_self();
    printf("Thread with ID %lu is running\n", (unsigned long)id);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_routine, NULL);
    pthread_create(&t2, NULL, thread_routine, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread is exiting\n");
    return 0;
}

/*
REPORT SECTION:

    pthread_create() is a function used to create a new thread in a program.
    It takes four arguments:
        a pointer to a pthread_t variable that will hold the thread ID,
        a pointer to a pthread_attr_t structure that specifies thread attributes (or NULL for default attributes),
        a pointer to the function that the thread will execute,
        and a pointer to the argument that will be passed to the thread function (or NULL if no argument is needed).

    pthread_join() is a function used to wait for a specific thread to finish its execution.
    It takes two arguments:
        the thread ID of the thread to wait for,
        and a pointer to a variable where the return value of the thread function will be stored (or NULL if not needed).

    A thread is ended when:
        the thread's execution function executes a return statement,
        the thread explicitly calls pthread_exit(),
        the thread is canceled by another thread via pthread_cancel(),
        or the process containing the thread calls exit() or is terminated by the operating system.
*/