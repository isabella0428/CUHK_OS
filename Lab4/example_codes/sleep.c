/* By using sleep(), parent can put to a suspended state 
and wait for the child. However, sleep() is not desirable 
(we need to specify the time...) */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("Before fork... \n");
    if(fork() == 0){
        printf("Hello World!");
        exit(0);
    }
    sleep(1);
    printf("After fork...\n");
    return 0;
}