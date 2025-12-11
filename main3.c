#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    pid_t pid1, pid2;
    int status;

    //seeding the random number generator
    srandom(time(NULL));

    //forking first child
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(1);
    }
    if (pid1 == 0) { 
        int iterations = random() % 30 + 1; // 1 to 30
        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            int sleep_time = random() % 10 + 1; // 1 to 10 seconds
            sleep(sleep_time);
            printf("Child Pid: %d is awake! Where is my Parent: %d?\n", getpid(), getppid());
        }
        exit(0);
    }

    //forking second child
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(1);
    }
    if (pid2 == 0) { 
        int iterations = random() % 30 + 1;
        for (int i = 0; i < iterations; i++) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            int sleep_time = random() % 10 + 1;
            sleep(sleep_time);
            printf("Child Pid: %d is awake! Where is my Parent: %d?\n", getpid(), getppid());
        }
        exit(0);
    }

    //parent waiting for both children
    pid_t finished_pid;
    for (int i = 0; i < 2; i++) {
        finished_pid = wait(&status);
        printf("Child Pid: %d has completed\n", finished_pid);
    }

    return 0;
}
