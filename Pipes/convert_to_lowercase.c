#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void convert_to_lowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main(int argc, char *argv[]) {
    int pipe_fd[2];
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipe_fd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork();

    if (pid > 0) { // Parent process
        close(pipe_fd[0]); 

        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        ssize_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            write(pipe_fd[1], buffer, bytes_read); 
        }

        fclose(file); 
        close(pipe_fd[1]); 
        wait(NULL); 
    } 
    else if (pid == 0) { // Child process
        close(pipe_fd[1]); // Close write end of the pipe

        ssize_t bytes_read;
        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer))) > 0) {
            convert_to_lowercase(buffer);
            write(STDOUT_FILENO, buffer, bytes_read); // Print lowercase data
        }

        close(pipe_fd[0]); // Close read end of the pipe
        exit(EXIT_SUCCESS);
    } 
    else { // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
