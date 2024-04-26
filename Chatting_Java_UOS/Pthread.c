#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *threadFunction(void *threadId){
    long tid;
    tid = (long) threadId;
    printf("Hello from Thread %ld\n",threadId);
    pthread_exit(NULL);
}

int main(){

    pthread_t thread[3];
    int rc;
    long t;

    for(t=0;t<3;t++){
        rc = pthread_create(&pthread_t[t],NULL,threadFunction,(void *)t);

        if(rc){
            printf("Error creating Threads");
            exit(-1);
        }
    }
    pthread_exit(NULL);

}