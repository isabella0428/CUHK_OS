#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    while(1){
        printf("Press Enter to execute ls\n");
        while(getchar() != '\n');
        if(!fork()){
            execl("/bin/ls", "ls", NULL);
        }
        else{
            wait(NULL);
        }
    }
    return 0;
}