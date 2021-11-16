#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void child(){
    printf("Child PID: %d\n", getpid());
    sleep(rand() % 4 + 2);
    printf("Child PID: %d finished\n", getpid());
}

void parent(){
    printf("Parent to fork off PID: %d\n", getpid());

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
            child();
        }
    }else{
        child();
    }
}