/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int alarm_completed = 0;
int count = 0;

void timeHandler(signum) {
  printf("\n%d alarms occured and it took %d seconds\n", count, count);
  exit(0);
}

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarm_completed = 1;
  count++;
}

int main(int argc, char * argv[])
{
  signal(SIGINT, timeHandler);
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1) {
    alarm_completed = 0;
    while(alarm_completed == 0);//busy wait for signal to be delivered
    alarm(1);
  } 
  return 0; //never reached
}