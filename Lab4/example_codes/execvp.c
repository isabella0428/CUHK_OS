#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *arg[] = {"ls", "-l", NULL};
    printf("Using *execvp* to exec ls -l ...\n");
    execvp("ls", arg);
    printf("Program terminated!\n");
    return 0;
}