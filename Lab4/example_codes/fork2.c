#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int res;
    printf("Before fork(), my PID is [%d]\n", getpid());
    res = fork();
    printf("The value of res is [%d]\n", getpid());
    if(res == 0){
        printf("I am a child! PID :[%d]\n", getpid());
    }
    else{
        printf("I am a parent! PID :[%d]\n", getpid());
    }
    printf("Process terminated!\n");
    return 0;
}