#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("\033[5;31mHello, World!\033[0m");  // Start blinking in red (31)
        fflush(stdout);  // Flush the output buffer
        sleep(1);  // Wait for 1 second
        printf("\r\033[5;34mHello, World!\033[0m");  // Clear the blinking text and start blinking in blue (34)
        fflush(stdout);  // Flush the output buffer
        sleep(1);  // Wait for 1 second
    }
    return 0;
}
