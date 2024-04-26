#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){

    pid_t pid;
    int status;


    pid = fork();


    if(pid<0){
        perror("Forkk Failed");
    }
    else if(pid==0){
        execl("/bin/ls","ls","-l",NULL);

        // Takes array of String
        char *args[] = {"ls","-l",NULL};
        execv("/bin/ls",args);

        // Searches for Executable File ls in the directory listed to PATH env variable
        execlp("ls", "ls", "-l", NULL);

        //  Searches for Executable File passed in args
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);

        char *envp[] = {"PATH=/bin", NULL};
        execle("/bin/ls", "ls", "-l", NULL, envp);


        perror("exec failed");
        return 1;


    }
    else{
        waitpid(pid, &status, 0);
        printf("Child exited with status %d\n", status);
    }
    return 0;
}