/*signal2.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t got_signal = 0;

void handler(int signum){
  printf("Hello World!\n");
  got_signal = 1;
}

int main(int argc, char *argv[]){
  signal(SIGALRM, handler);

  while (1){
    alarm(5);    //alarm scheduled for 5 seconds
    got_signal = 0;

    while (!got_signal){
    //waiting
    }
    printf("Turing was right!\n");
  }
  return 0;
}
