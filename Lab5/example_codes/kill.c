#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/* send a signal to the process if the segmentation error occurs */
int main(int argv, char *argc[]){
    printf("My PID is : %d ",getpid());
    sleep(5);
    kill(getpid(), SIGSEGV);
    return 0;
}