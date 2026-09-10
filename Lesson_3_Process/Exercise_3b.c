#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process (PID: %d)\nPPID: %d\n", getpid(), getppid());
        sleep(2);
    }
    else {
        printf("Parent process (PID: %d)\n", getpid());
        exit(0); //Parent process exits immediately, child becomes orphan
    }
}

/*
REPORT SECTION:

    Occurs when a parent process terminates while its child process is still running.

    To prevent unmanaged processes, Linux automatically re-parents the orphan process
to the root process (init / systemd, PID = 1). This ensures its resources are properly
reclaimed when it eventually terminates.
*/