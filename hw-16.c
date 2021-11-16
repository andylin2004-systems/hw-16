#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

unsigned int randomNum(){
    unsigned int random;
    FILE *file = open("/dev/random", O_RDONLY, 0644);
    read(file, &random, 4);
    return random;
}

int child(){
    printf("Child PID: %d\n", getpid());
    int sleepTime = (randomNum() % 4) + 2;
    printf("%d\n", sleepTime);
    sleep(sleepTime);
    printf("Child PID %d finished\n", getpid());
    return sleepTime;
}

void parent(){
    int status;
    printf("Parent to fork off PID: %d\n", getpid());
    int pid = wait(&status);
    printf("A child process with PID %d terminated after %d seconds.\nProcess terminated.", pid, WEXITSTATUS(status));
}

int main(){
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