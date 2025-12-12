/*timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t alarms = 0;
time_t start_time;

void alarm_handler(int signum){
  alarms++;
}

void int_handler(int signum){
  time_t end_time = time(NULL);
  printf("\nProgram ran for %ld seconds.\n", end_time - start_time);
  printf("Total alarms received: %d\n", alarms);
  exit(0);
}

int main(){
  start_time = time(NULL);

  signal(SIGALRM, alarm_handler);
  signal(SIGINT, int_handler);

  while (1){
    alarm(1);    
    pause();
    }

  return 0;
}
