#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t p1, p2;
int turn = 0;
int switch_count = 0;  // no of times process switch happened
int max_switches = 10;  // max no of process switch allowed

void scheduler(int sig) {
    if (switch_count >= max_switches) { // checking if context switching is allowed
        kill(p1, SIGKILL); //killing process with pid p1
        kill(p2, SIGKILL); //killing process with pid2
        wait(NULL);  
        wait(NULL);
        printf("Scheduling complete.\n");
        _exit(0);
    }

    if (turn == 0) {
        kill(p2, SIGSTOP);//immediately stopping the p2 process
        kill(p1, SIGCONT); //resuming the process p1 since turn =0
        turn = 1;  // changing to alter the process in next 
    } else {
        kill(p1, SIGSTOP);  //immediately stopping the p1 process
        kill(p2, SIGCONT);  //resuming the process p2 since turn =1
        turn = 0;    // changing to alter the process in next
    }

    switch_count++; //increasing no of context switching happened
    alarm(1);   //setting time when to start next scheduling
}

void handler_p1(int sig) {
    printf("Process 1 is running\n");
    fflush(stdout);   //output apper immediately 
}

void handler_p2(int sig) {
    printf("Process 2 is running\n");
    fflush(stdout);
}

int main() {
    signal(SIGALRM, scheduler); // this tells when alarm sign is sent, scheulder function is invoked (this is a signal handler)
 
    p1 = fork();
    if (p1 == 0) {
        signal(SIGCONT, handler_p1);// invokes handler_p1 with a signal to continue
       
        kill(getpid(), SIGSTOP); 
        while (1) pause();
    }

    p2 = fork();    // creating second child process 
    if (p2 == 0) {
        signal(SIGCONT, handler_p2);  // invokes handler_p2 with a signal to continue
       
       
        kill(getpid(), SIGSTOP);   // Child 1 gets paused after handler_p2
        while (1) pause(); 
    }

   
    sleep(1);

    alarm(1);  // Start scheduler

    while (1) pause();

    return 0;
}

