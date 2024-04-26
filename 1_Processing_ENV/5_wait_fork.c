#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main(){
  
   pid_t pid;

   pid = fork();

   if(pid<0){
    perror("Fork Failed");
    exit(EXIT_FAILURE);
   }

   else if(pid == 0){
    printf("Child Process Executing...\n");
    printf("Child Process with PID: %d",getpid());
   }

   else{
      printf("Parent process with PID: %d\n",getpid());
      printf("Waiting for Child Process to finish\n");
      wait(NULL);
      printf("Child Process Ended");
   }
   return 0;
}