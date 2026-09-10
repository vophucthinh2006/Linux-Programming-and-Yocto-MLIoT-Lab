#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    setenv("MY_COMMAND", "ls", 1); //1 is overwrite flag: if the variable "MY_COMMAND" already exists, it will be overwritten "ls"
    
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        char *cmd = getenv("MY_COMMAND");
        if (cmd != NULL) {
            printf("Child process (PID: %d) executing command: %s\n", getpid(), cmd);

            execlp(cmd, cmd, "-l", NULL); //NULL indicates the end of the argument list for execlp

            perror("execlp failed");
            exit(1);
        }
    }
    else {
        wait(NULL); // Wait for the child process to complete (Don't care about the exit status in this case)
    }
    return 0;
}

/*
REPORT SECTION:

    Upon a successful exec() call, the Kernel completely wipes the child process's entire address
space—including the Text (code), Data, Heap, and Stack segments—and replaces it with the binary image of the
new program.

    The original program instructions immediately cease execution. The process begins executing the new code
from its main entry point.

    The process retains its underlying identity and context, such as its Process ID (PID), Parent Process ID
(PPID), open File Descriptors, and environment variables.

    An exec() function call never returns to the original code on success, as the calling instructions no longer
exist in memory. It only returns -1 if an error occurs.
*/