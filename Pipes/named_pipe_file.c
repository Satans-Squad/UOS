#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "my_fifo"
#define OUTPUT_FILE "output_file.txt"
#define BUFFER_SIZE 1024

int main() {
    int fd_fifo, fd_output;
    char buffer[BUFFER_SIZE];

    // Create the named pipe (FIFO)
    if (mkfifo(FIFO_FILE, 0666) == -1) {
        perror("Error creating FIFO");
        exit(EXIT_FAILURE);
    }

    int pid = fork();

    if (pid > 0) { // Parent process
        printf("Parent Executing...\n");

        // Open FIFO for writing
        fd_fifo = open(FIFO_FILE, O_WRONLY);
        if (fd_fifo == -1) {
            perror("Error opening FIFO for writing");
            exit(EXIT_FAILURE);
        }

        // Open the file to send
        FILE *file = fopen("send.txt", "r");
        if (file == NULL) {
            perror("Error opening file for reading");
            exit(EXIT_FAILURE);
        }

        // Read from the file and write to FIFO
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
        write(fd_fifo, buffer, bytes_read);


        // Close the file and FIFO
        fclose(file);
        close(fd_fifo);
    } 
   else if (pid == 0) { // Child process
    printf("Child Executing...\n");

    fd_fifo = open(FIFO_FILE, O_RDONLY);
    if (fd_fifo == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    ssize_t bytes_read;
    while ((bytes_read = read(fd_fifo, buffer, sizeof(buffer))) > 0) {
        // Null-terminate the buffer to safely print it as a string
        buffer[bytes_read] = '\0';
        printf("Received data from FIFO: %s\n", buffer);
    }

    if (bytes_read == -1) {
        perror("Error reading from FIFO");
        exit(EXIT_FAILURE);
    }

    // Close the FIFO
    close(fd_fifo);
    }

    else { // Fork failed
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }


    unlink(FIFO_FILE);

    return 0;
}
