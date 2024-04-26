#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 1234

int main() {
    int semid;

    // Create or get semaphore
    if ((semid = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0666)) == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Display semaphore ID
    printf("Semaphore ID: %d\n", semid);

    // Set semaphore value to 1
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
