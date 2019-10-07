#include<stdio.h>
#include<signal.h>

// This is a test Function i used to learn the function use
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n"); 
} 
// this is the sighub function that runs when SIGHUB signal is called 
  void sighub(int sig){
    printf("CHILD: Received a SIGHUP"); 
    return 0;
  }
  // this is the sigint function that runs when SIGINT signal is called 

  void sigint(int sig){
    printf("CHILD: Received a SIGINT"); 
    return 0;
  }
    // this is the sigquit function that runs when SIGQUIT signal is called 

  void sigquit(int sig,int pid){
    kill(pid,SIGINT);
    printf("My DADDY killed me"); 
    return 0;
  }
int main() 
{ 
  // this saves the childs PID
    int pid1;
    pid1 = fork();
    // this runs the SIGHUB command
    signal(SIGHUB, sighub); 
    printf("PARENT: Sending SIGHUP"); 
    sleep(3);
        // this runs the SIGINT command
    printf("PARENT: Sending SIGINT");
    signal(SIGINT, sigint); 
    sleep(3);
        // this runs the SIGQUIT command
    printf("PARENT: Sending SIGQUIT");
    signal(SIGQUIT, sigquit); 
    sleep(3);
    return 0; 
} 