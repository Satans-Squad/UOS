#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 100

// int main() {
//     int pipe_fd[2];
//     pid_t pid;
//     char buffer[BUFFER_SIZE];

//     // Create a pipe
//     if (pipe(pipe_fd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     // Fork the process
//     pid = fork();

//     if (pid > 0) {  // Parent process
//         close(pipe_fd[0]);

//         char message[] = "Hello, child process!";
//         write(pipe_fd[1], message, sizeof(message));
//         printf("Parent sent: %s\n", message);

//         close(pipe_fd[1]);
//     } else if (pid == 0) {  // Child process
//         close(pipe_fd[1]);

//         read(pipe_fd[0], buffer, BUFFER_SIZE);
//         printf("Child received: %s\n", buffer);

//         close(pipe_fd[0]);
//     } else {  // Fork failed
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     return 0;
// }


int main(){
    int fd[2];
    char buffer[BUFFER_SIZE];

    if(pipe(fd)==-1){
        perror("Error");
        exit(1);
    }
    printf("Pipe Created Successfully\n");

    int pid = fork();

    if(pid < 0){
        perror("Error in forking");
        exit(EXIT_FAILURE);
    }
    else if(pid>0){
        close(fd[0]);
        char message[] = "hello from Parent";

        write(fd[1],message,sizeof(message));
        printf("Parent sent the message -  %s\n",message);
        close(fd[1]);
    }
    else{
        printf("Child Process Created\n");
        close(fd[1]);

        read(fd[0],buffer,BUFFER_SIZE);
        printf("Child Process reaading from pipe - %s",buffer);
        close(fd[1]);
    }

    return 0;
}