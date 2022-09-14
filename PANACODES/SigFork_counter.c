// #include<stdio.h>
// #include<wait.h>
// #include<signal.h>
// #include<stdlib.h>
// #include <unistd.h>
// pid_t pid;
// int counter = 0;
// void handler1(int sig)
// {
//   counter++;
//   printf("counter = %d\n", counter);
//   /* Flushes the printed string to stdout */
//   fflush(stdout);
//  }
// void handler2(int sig)
// {
//   counter += 3;
//   printf("counter = %d\n", counter);
//   exit(0);
// }

// int main()
// {
//   pid_t p;
//   int status;
//   signal(SIGINT, handler1);
//   if ((pid = fork()) == 0)
//   {
//     signal(SIGINT, handler2);
//     while(1) ;
//   }
//   if ((p = wait(&status)) > 0)
//   {
//     counter += 4;
//     printf("counter = %d\n", counter);
//   }
// }
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int count = 0;
int child_pid;

void signalHandler(int sig){

    printf("count = %d\n", count);
    // exit(0);
}

void signalHandler2(int sig){

    //printf("count = %d\n", count);
    // exit(0);
}

int main(){

    int i, signum; // for loop iterator
    pid_t pid; // pids of child processes

    //signal(SIGINT, signalHandler);
    signal(SIGINT, signalHandler2);

    // Fork 3 child processes
    pid = fork();
    if(!pid){ // If child process
    signal(SIGINT, signalHandler);
        child_pid = getpid();
        while(1){
            count++;

        }
    }else if(pid > 0){

       wait(&child_pid);
        // while(1){
        //     count++;
        // }
    }
}
