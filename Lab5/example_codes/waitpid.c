#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int pid;
    int status;
    if(!(pid = fork())){
        /* parent */
        printf("My PID: %d\n", getpid());
        exit(0);
    }
    waitpid(pid, &status, WUNTRACED);
    if(WEXITSTATUS(status)){
        printf("Exit normally\n");
        printf("Exit status: %d\n", WEXITSTATUS(status));
    }
    else{
        printf("Exit Not Normal\n");
    }
    return 0;
}