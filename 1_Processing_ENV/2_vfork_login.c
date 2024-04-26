#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h> 


int main(){

    pid_t pid;

    char *login;

    pid = vfork();

    if(pid<0){
        perror("Error vforking");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0){
        login = getlogin();
        
        printf("Login Name using Child Process->> %s\n",login);
        exit(EXIT_SUCCESS);
    }

    else{
        wait(NULL);
        char password[50];
        printf("Enter Password:->");
        scanf("%s",&password);
        printf("Password using Parent--> %s",password);
    }
    return 0;    
}


































