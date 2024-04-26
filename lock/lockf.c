#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;
    char filename[] = "lockfile.txt";

    // Open or create the file
    if ((fd = open(filename, O_RDWR | O_CREAT, 0666)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        printf("Child process trying to lock the file...\n");

        // Try to acquire a lock on the file
        if (lockf(fd, F_TLOCK, 0) == -1) {
            perror("lockf");
            exit(EXIT_FAILURE);
        }

        printf("Child process acquired the lock.\n");
        sleep(5); // Simulate some work

        // Release the lock
        printf("Child process releasing the lock.\n");
        if (lockf(fd, F_ULOCK, 0) == -1) {
            perror("lockf");
            exit(EXIT_FAILURE);
        }
        printf("Child process released the lock.\n");
    } else { // Parent process
        printf("Parent process trying to lock the file...\n");

        // Try to acquire a lock on the file
        if (lockf(fd, F_TLOCK, 0) == -1) {
            perror("lockf");
            exit(EXIT_FAILURE);
        }

        printf("Parent process acquired the lock.\n");
        sleep(2); // Simulate some work

        // Release the lock
        printf("Parent process releasing the lock.\n");
        if (lockf(fd, F_ULOCK, 0) == -1) {
            perror("lockf");
            exit(EXIT_FAILURE);
        }
        printf("Parent process released the lock.\n");
    }

    // Close the file
    close(fd);
    
    return 0;
}
