#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int pipefds[2];
    char buffer[30];
    /* create pipe */
    if (pipe(pipefds) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    } 
    //write to pipe
    printf("Writing to file descriptor #%d\n", pipefds[1]);
    write(pipefds[1], "CSCI3150", 9);
    //read from pipe
    printf("Reading from file descriptor #%d\n", pipefds[0]);
    read(pipefds[0], buffer, 9);
    printf("read \" %s \" \n ", buffer);
    return 0;
}
