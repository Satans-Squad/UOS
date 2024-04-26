#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
    pid_t pid;
    int status;


    pid = fork();

    if(pid < 0){
        perror("Fork failed");
        exit(EXIT_FAILURE); // return 1
    }
    else if(pid == 0){
        printf("Child Process Executing...\n");
        sleep(2);
        printf("Child Process Ending...\n");
        exit(123);
    }
    else{
        printf("Parent process Executing...\n");
        wait(&status);
        printf("Parent Waiting for Child to Terminate...\n");

        printf("Parent Terminating...\n");
        exit(0);
    }

    return 0;
}