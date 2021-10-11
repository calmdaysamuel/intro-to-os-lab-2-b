/* tiemr.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int times_executed = 0;
void signal_handler(int signal_num) {
  times_executed += 1;
  alarm(1);
}

void time_logger(int signal_num) {
  printf("\n%d function calls took %d seconds\n", times_executed, times_executed);
  exit(1);
}
int main(int argc, char * argv[])
{
  signal(SIGINT, time_logger);
  signal(SIGALRM, signal_handler);
  alarm(1);
  while(1) {
    
  }
}