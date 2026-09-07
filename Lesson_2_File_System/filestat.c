#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argument_count != 2) {
        printf("Usage: ./filestat <file_path>");
        return 1;
    }
    struct stat file_stat;
    if (lstat(argv[1], &file_stat) = -1) {
        perror("Error getting file stats.");
        return 1;
    }
    printf("File path: %s\n", argv[1]);
    printf("File type: ");
    if (S_ISREG(file_stat.st_mode)) {
        printf("Regular File.\n");
    }
    elif (S_ISDIR(file_stat.st_mode)) {
        printf("Directory.\n");
    }
    elif (S_ISLNK(file_stat.st_mode)) {
        printf("Symbolic Link.\n");
    }
}