#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        //Child process
        printf("Child process (PID: %d)\n", getpid());
        exit(10);
    }
    else {
        //Parent process
        printf("Parent process (PID: %d)\nChild PID: %d\n", getpid(), pid);

        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}