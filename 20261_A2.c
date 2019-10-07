#include<stdio.h>
#include<signal.h>


void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n"); 
} 
  void sighub(int sig){
    printf("CHILD: Received a SIGHUP"); 
    return 0;
  }
  void sigint(int sig){
    printf("CHILD: Received a SIGINT"); 
    return 0;
  }
  void sigquit(int sig,int pid){
    kill(pid,SIGINT);
    printf("My DADDY killed me"); 
    return 0;
  }
int main() 
{ 
    int pid1;
    pid1 = fork();
    signal(SIGHUB, sighub); 
    printf("PARENT: Sending SIGHUP"); 
    sleep(3);
    signal(SIGINT, sigint); 
    sleep(3);
    printf("PARENT: Sending SIGINT");
    signal(SIGQUIT, sigquit); 
    sleep(3);
    return 0; 
} 