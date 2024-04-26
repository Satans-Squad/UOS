#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<stdbool.h>


bool flag=false;
void alarmhandle(int sig){
    printf("Input Time Expired\n");
    exit(1);
}

int main(){
    int a=0;
    printf("Enter Input within 10 secs:\n");
    // sleep(1);
    alarm(5);
    signal(SIGALRM,alarmhandle);
    scanf("%d",&a);
    printf("You Entered %d\n",a);
}