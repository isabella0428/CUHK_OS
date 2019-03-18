/* This script is about changing the current working directory (cwd) of the current process */
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[PATH_MAX];
    char input[255];
    if(getcwd(buf, PATH_MAX + 1) != NULL){
        printf("Now it is %s\n", buf);
        printf("Where do you want to go?\n");
        fgets(input, 255, stdin);
        input[strlen(input) - 1] = '\0';
        if(chdir(input) != -1){
            getcwd(buf, PATH_MAX + 1);
            printf("Now it is %s\n", buf);
        }
        else{
            printf("Cannot Change Directory\n"); 
        }
    }
    return 0;
}