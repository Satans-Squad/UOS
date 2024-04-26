#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<stdlib.h>

#define SIZE 128
#define KEY 1234

typedef struct msgbuf{
    long mtype;
    char content[SIZE];
} message_buffer;

int main() {
    
    int mess_id;
    int buffer_length;
    message_buffer reciever_buffer;

    if(mess_id = msgget(KEY,0666) < 0){
        perror("Error is Recieving Buffer");
        exit(1);
    }

    if(msgrcv(mess_id, &reciever_buffer,SIZE,1,0) < 0){
        perror("Error");
        exit(1);
    }
    

    if ((mess_id = msgget(KEY, 0666)) < 0) {
        perror("msgget");
        exit(1);
    }


    printf("%s\n", reciever_buffer.content);

    exit(0);
}
