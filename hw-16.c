#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int child(){
    printf("Child PID: %d\n", getpid());
    int sleepTime = (rand() % 4) + 2;
    sleep(sleepTime);
    printf("Child PID: %d finished\n", getpid());
    return sleepTime;
}

void parent(){
    int status;
    printf("Parent to fork off PID: %d\n", getpid());
    int pid = wait(&status);
    printf("A child process with PID %d terminated after %d seconds.\nProcess terminated.", pid, WEXITSTATUS(status));
}

int main(){
    srand(time(NULL));
    printf("Forking PID: %d\n", getpid());
    int fork1 = fork();
    if (fork1){
        int fork2 = fork();
        if (fork2){
            parent();
        }
        else
        {
            return child();
        }
    }else{
        return child();
    }
}