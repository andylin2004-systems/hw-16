#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void child(){
    printf("PID: %d\n", getpid());
    sleep(rand() % 4 + 2);
    printf("PID: %d\n finished", getpid());
}

int main(){
    srand(time(NULL));
}