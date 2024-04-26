#include <stdio.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Ctrl+C trapped. Press Ctrl+C again to quit.\n");
    signal(SIGINT, sigint_handler);
}

int main() {

    signal(SIGINT, sigint_handler);
    printf("Program running. Press Ctrl+C to trap the signal.\n");

    while(1) {
    }

    return 0;
}
