#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Using *execl* to exec ls -l...\n");
    execl("/bin/ls", "ls", NULL);
    /* After this step, the code of the process is changed to the 
    target program and it never returns to the original code. 
    As the result, the line Program Terminated is not printed. */
    printf("Program terminated\n"); 
    return 0;
}