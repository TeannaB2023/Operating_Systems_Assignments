/* hello_signal.c 
 * Collaborator: Javid
 * For multiple signals: https://www.csl.mtu.edu/cs4411.ck/www/NOTES/signal/two-signals.html */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarm_completed = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(1);
  alarm_completed = 1;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1) { 
    alarm_completed = 0;
    alarm(1);
    while(alarm_completed == 0);//busy wait for signal to be delivered
    printf("Turing was right!\n");
    } 
  return 0; //never reached
}