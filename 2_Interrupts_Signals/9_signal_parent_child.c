#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void signal_handler(int signum){
    printf("Signal Recieved from parent\n");
}

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0){
        printf("Child Process Created\n");
        signal(SIGUSR1,signal_handler);
        printf("Ready to recieve Signal\n");
        for (;;);
        exit(0);
    }
    else{
        printf("Parent process Created\n");
        sleep(2);
        printf("Sending Signal to Child process");

        kill(pid,SIGUSR1);
        wait(NULL);

        exit(0);
    }
    return 0;
}
