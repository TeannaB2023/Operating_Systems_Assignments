#include  <stdio.h>
#include  <sys/types.h>
#include  <stdlib.h>

#define   MAX_COUNT  700

/* Multi-child fork line from: https:
 * //stackoverflow.com/questions/6542491/how-to-create-two-processes-from-a-single-parent */

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid1, pid2;
     
     (pid1 = fork()) && (pid2 = fork());
  
     if (pid1 < 0 || pid2 < 0)
       printf("Error, in forking");
     else if (pid1 == 0)
          ChildProcess();
     else if (pid2 == 0)
          ChildProcess();
     else 
          wait(pid1);
          wait(pid2);
          ParentProcess();
}

void  ChildProcess(void)
{
  int   i;
  
  srandom(getpid()); // How to seed it correctly with unique numbers?
  int max_count = random() % 30;
     for (i = 1; i <= max_count; i++)
          printf("   This line is from child: %d, value = %d\n", getpid(), i);
  sleep(random() % 10);   
  printf("   *** Child process is done. Where is my parent, %d?***\n", getppid());
  exit(0);
}

void  ParentProcess(void)
{
     int   i;
     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent: %d, value = %d\n", getpid(), i);
     printf("*** Parent is done ***\n");
}