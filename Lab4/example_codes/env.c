#include <stdio.h>
int main(int agrc, char *argv[], char* envp[]){
    int i;
    for (i = 0; envp[i]; i++){
        printf("[%d]: %s\n", i, envp[i]);
    }
    return 0;
}