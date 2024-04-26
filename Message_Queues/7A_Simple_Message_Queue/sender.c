#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128
#define KEY 215

typedef struct msgbuf{
    long mtype;
    char content[SIZE];
} message_buffer;


int main(){
    int mess_id;
    message_buffer sender_buffer;
    int buffer_length;


    if(mess_id = msgget(KEY, IPC_CREAT | 0666) <0 ){
        perror("Error creating Message Queue");
        exit(EXIT_FAILURE);
    }

    sender_buffer.mtype = 1;
    strcpy(sender_buffer.content,"Hello Soham, from Sender");
    buffer_length = strlen(sender_buffer.content) + 1;

    if(msgsnd(mess_id,&sender_buffer,buffer_length,IPC_NOWAIT) < 0){
        perror("Error in Sending Message");
        exit(1);
    }
    else{
        printf("Message: %s sent",sender_buffer.content);
    }
    exit(0);
}