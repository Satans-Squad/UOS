#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handler(int signum) {
    printf("Received Signal by process: %d\n", getpid());
}

int main() {
    signal(SIGUSR1, signal_handler);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child Process created with ID: %d\n", getpid());
        printf("Waiting for Signal from Parent\n");
        pause();
    } else {
        sleep(1); // Adjust the duration if needed
        printf("Parent Process with PID: %d\n", getpid());

        // Wait for child to be created

        printf("Sending Signal to Child\n");
        kill(pid, SIGUSR1);
        wait(NULL);
        printf("Child Process Completed\n");
    }
    return 0;
}
