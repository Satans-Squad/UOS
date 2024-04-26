#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
    pid_t pid;

    pid = vfork();

    if(pid < 0){
        perror("Vfork Failed");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0){
        printf("Child Process Executing");
        execl("/usr/bin/nano","nano",NULL);
        perror("execl failed");
        _exit(EXIT_FAILURE);
    }

    else{
        printf("Parent Waiting");
        wait(NULL);
        printf("Parent Exiting");
    }
    return 0;
}