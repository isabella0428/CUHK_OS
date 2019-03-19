#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Try to execute lls\n");
    execl("/bin/lls", "lls", NULL);
    /* errno is a global variable that stores the error number */
    printf("execl returned! error is [%d]\n", errno);
    perror("The error message is:");
    return 0;
}