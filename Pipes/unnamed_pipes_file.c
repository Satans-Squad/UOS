#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

#define FILE_SEND "send.txt"
#define SIZE 1024

int main() {

    int pipe_fd[2];

    if(pipe(pipe_fd) == -1){
        perror("Error Creating Pipe");
        exit(1);
    }

    FILE *file = fopen(FILE_SEND, "w");
    if (file == NULL) {
        perror("Error in Opening File");
        exit(1);
    }

    printf("Enter 'A' to 'Z' or '1' to '100' that will be stored in send.txt File: ");
    char buffer[SIZE];
    fgets(buffer, SIZE, stdin);
    fprintf(file, "%s", buffer); 
    fclose(file);

    int pid = fork();

    if (pid > 0) {
        printf("Parent Executing...\n");
        close(pipe_fd[0]); 

        write(pipe_fd[1], FILE_SEND, strlen(FILE_SEND) + 1);

        close(pipe_fd[1]);

        
        wait(NULL);
    } 
    else if (pid == 0) { // Child process
        printf("Child Executing...\n");
        close(pipe_fd[1]); 

        char buffer[1024];
        printf("Reading data from pipes\n");

        read(pipe_fd[0],buffer,sizeof(buffer));
        printf("Contents are:- %s\n",buffer);

        FILE *file =  fopen(buffer,"r");
        if(file == NULL){
            perror("File");
            exit(1);
        }

        char content[SIZE];
        fread(content,1,SIZE-1,file);
        printf("Contents are: %s\n",content);
        fclose(file);
        close(pipe_fd[0]); 
    } 
    else { // Fork failed
        perror("Fork Failed");
        exit(1);
    }

    return 0;
}
