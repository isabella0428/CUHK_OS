#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int pipefds[2];
    int pipefdsl[2];
    pid_t pid, pid1, pid2;
    int status;

    if (pipe(pipefds) == -1){
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefdsl) == -1){
        perror("pipe2");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    if (pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid == 0){
	    close(pipefdsl[1]);
	    close(pipefdsl[0]);
        close(pipefds[0]);
        dup2(pipefds[1], STDOUT_FILENO);
        close(pipefds[1]);
        execlp("ls", "ls", NULL);
        }
    else{
        pid1 = fork();
        if(pid1 == 0){
            close(pipefds[1]);
            close(pipefdsl[0]);
            dup2(pipefds[0], STDIN_FILENO);
            close(pipefds[0]);
            dup2(pipefdsl[1], STDOUT_FILENO);
            close(pipefdsl[1]);
            execlp("cat", "cat", NULL);
            }
        else{
            pid2 = fork();
            if(pid2 == 0){
		        close(pipefds[0]);
		        close(pipefds[1]);
                close(pipefdsl[1]);
                dup2(pipefdsl[0], STDIN_FILENO);
                close(pipefdsl[0]);
                execlp("cat", "cat", NULL);
            }
	        close(pipefds[0]);
	        close(pipefds[1]);
	        close(pipefdsl[0]);
	        close(pipefdsl[1]);
            waitpid(pid, &status, WUNTRACED);
            waitpid(pid1, &status, WUNTRACED);
            waitpid(pid2, &status, WUNTRACED);
            }
    }
    return 0;
}
