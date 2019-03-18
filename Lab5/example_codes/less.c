#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int pipefds[2];
    pid_t pid, pid1;
    if(pipe(pipefds) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if(pid ==  -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0){
        //child
        close(pipefds[1]);
        dup2(pipefds[0], STDIN_FILENO);
        close(pipefds[0]);
        execlp("less", "less", NULL);
    }
    else{
        //parent
        pid1 = fork();
        if(pid == 0){
            close(pipefds[0]);
            dup2(pipefds[1], STDOUT_FILENO);
            close(pipefds[1]);
            execlp("ls", "ls", NULL);
        }
        close(pipefds[0]);
        close(pipefds[1]);
        waitpid(pid, &status, WUNTRACED);
        waitid(pid1, &status, WUNTRACED);
    }
}