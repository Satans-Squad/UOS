#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("Child process executing...\n");
        // execl("/usr/bin/nano", "nano", NULL);
        execl("/bin/ls","ls","-l",NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process waiting...\n");
        wait(NULL); 
        printf("Child Process Ended...\n");
        printf("Parent process exiting...\n");
    }

    return 0;
}
