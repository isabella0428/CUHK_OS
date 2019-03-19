#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int pid;
    int status;
    if(!(pid = fork())){
        printf("My PID: %d\n", getpid());
        exit(0);
    }
    waitpid(pid, &status, WUNTRACED);
    if(WIFEXITED(status)){
        printf("Exited normally!\n");
        printf("Exit Status: %d\n", WEXITSTATUS(status));
    }
    else{
        printf("Exit not normal\n");
    }
    return 0;
}