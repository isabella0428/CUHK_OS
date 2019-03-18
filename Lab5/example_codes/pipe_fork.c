#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int pipefds[2];
    char buffer[30];
    //create pipe
    if (pipe(pipefds) == -1){
        perror("pipt");
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    pid = fork();
    memset(buffer, 0, 30);

    if(pid > 0){
        printf("Parent write in pipe\n");
        //parent close the read end
        close(pipefds[0]);
        //parent write in the pipe write end
        write(pipefds[1], "CSCI3150", 9);
        //after finishing writing, parent close the write end
        close(pipefds[1]);
        //parent wait for child
        wait(NULL);
    }
    else{
        //child close the write end
        close(pipefds[1]);
        //child read from the pipe read end until the pipe is empty
        while (read(pipefds[0], buffer, 1) == 1){
            printf("CHILD read from pipe -- %s\n", buffer);
        }
        //after finishing reading, child close the read end
        close(pipefds[0]);
        printf("CHILD: EXITING!");
        exit(EXIT_SUCCESS);
    }
    return 0;
}