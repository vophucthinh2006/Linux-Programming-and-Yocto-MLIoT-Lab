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
        printf("Child process (PID: %d)\n", getpid());
        exit(0);
    }
    else {
        printf("Parent process (PID: %d), sleeping for 30s without wait()", getpid());
        sleep(30); //Child process is a zombie for 30 seconds
    }
    return 0;
}

/*
REPORT SECTION:
    Occurs when a child process terminates, but its parent process has not yet called wait() to read its exit status.
    
    The Kernel temporarily retains the process's record (Process Table Entry). Unhandled zombie leaks can exhaust
available Process IDs (PIDs) in the system.
*/