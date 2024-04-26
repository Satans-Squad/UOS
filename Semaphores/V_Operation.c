#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 1234

void V(int semid) {
    struct sembuf sb;

    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;

    if (semop(semid, &sb, 1) == -1) {
        perror("semop");
        exit(EXIT_FAILURE);
    }

    printf("Performed V operation on semaphore %d\n", semid);
}

int main() {
    int semid;

    // Get semaphore
    if ((semid = semget(SEM_KEY, 1, 0)) == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Perform V operation
    V(semid);

    return 0;
}
