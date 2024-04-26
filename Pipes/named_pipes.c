#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sys/wait.h>

#define FIFO_FILE "fifo"


int main(){
    int fd;

    if(mkfifo(FIFO_FILE,0666) == -1){
        perror("Error in creating\n");
        exit(1);
    }
    int pid = fork();

    if(pid > 0){
        printf("Parent Executing...\n");

        fd = open(FIFO_FILE,O_WRONLY);
        if(fd == -1){
            perror("error");
            exit(1);
        }

        char message[] = "Hello from Parent";
        write(fd,message,strlen(message));

        close(fd);
    }
    else if(pid == 0){
        fd = open(FIFO_FILE,O_RDONLY);
        if(fd == -1){
            perror("error");
            exit(1);
        }
        printf("Child recieved data\n");
        char buffer[100];

        read(fd,buffer,sizeof(buffer));
        printf("Data->: %s",buffer);
        close(fd);
    }
    else{
        perror("fork failed");
        exit(1);
    }


    return 0;
}