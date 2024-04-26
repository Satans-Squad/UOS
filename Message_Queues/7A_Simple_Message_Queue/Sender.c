#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128
#define KEY 1234

typedef struct msgbuf{
    long mtype;
    char content[SIZE];
} messsage_buffer;

int main() {
    
    int mess_id;
    int buffer_length;
    messsage_buffer sender_buffer;

    if(mess_id = msgget(KEY, IPC_CREAT | 0666) <0 ){
        perror("Error creating Message Queue");
        exit(EXIT_FAILURE);
    }

    sender_buffer.mtype = 1;
    strcpy(sender_buffer.content,"Greetings Soham from Sender...");
    buffer_length = strlen(sender_buffer.content) + 1;


    if(msgsnd(mess_id,&sender_buffer,buffer_length, IPC_NOWAIT) <0 ){
        perror("Error in msgsnd");
        exit(1);
    }
    else{
        printf("Message:\"%s\" Sent\n",sender_buffer.content);
    }
    exit(0);
   
}
