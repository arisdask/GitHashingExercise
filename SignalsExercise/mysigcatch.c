#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handle_sigint(int sig) {
    printf("\nCaught signal %d (SIGINT). See ya!!\n", sig);
    exit(0);
}

int main() {
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        fprintf(stderr, "Error: Unable to catch SIGINT\n");
        exit(EXIT_FAILURE);
    }

    printf("Program is running! Press Ctrl+C to generate a SIGINT signal.\n");

    while (1) {
        printf("Press Ctrl+C to exit...\n");
        sleep(2);
    }

    return 0;
}
