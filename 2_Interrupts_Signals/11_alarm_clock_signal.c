#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handleAlarm(int signum){
    printf("Alarm Triggered...\n");
}

int main(){



    printf("Setting Alarm for 5 secs\n");

    alarm(5);
    signal(SIGALRM,handleAlarm);

    return 0;
}