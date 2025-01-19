#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


// Counter to track the number of SIGINT signals caught
volatile sig_atomic_t sigint_count = 0;

// Custom signal handler function
void custom_sigint_handler(int sig) {
    sigint_count++;
    printf("\nCaught signal %d (SIGINT) %d time(s)\n", sig, sigint_count);
    
    if (sigint_count >= 2) {
        printf("Default SIGINT behavior restored. Next SIGINT will terminate the program.\n");
        if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
            fprintf(stderr, "Error: unable to restore default SIGINT handler\n");
            exit(1);
        }
    }
}

int main() {
    if (signal(SIGINT, custom_sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Error: unable to catch SIGINT\n");
        exit(EXIT_FAILURE);
    }

    printf("Program is running! Press Ctrl+C to generate a SIGINT signal.\n");

    while (1) {
        printf("Press Ctrl+C :/\n");
        sleep(2);
    }

    return 0;
}
