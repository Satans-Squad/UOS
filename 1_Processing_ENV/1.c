#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void child_task(int taskId){
    printf("Child Process %d Assigned. Executing Task...\n",taskId);
    printf("Child Process %d Ended\n",taskId);
    exit(EXIT_SUCCESS);
}


int main(){
    int children = 5;
    
    char *task[]  = {"Task 1","Task 2","Task 3","Task 4","Task 5"};
    printf("Parent Executing...\n");

    for(int i = 0; i < children; i++){
        pid_t children_id = fork();

        if(children_id == -1){
            perror("Fork Failed");
            exit(EXIT_FAILURE);
        }
        else if(children_id == 0){
            child_task(i);
        }

        printf("Parent Process Assigning task '%s' to child process\n",task[i]);
        // wait(NULL);
    }

    printf("Parent Process Ended\n");
    return 0;
}
