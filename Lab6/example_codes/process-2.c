/*process-2.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    sem_t *mutex;
    int value = 1;
    char *c = "This is CSCI3150 -- An Operating System course!\n";
    setbuf(stderr, NULL);
    sem_wait(mutex);
    mutex = sem_open("mutex", O_CREAT, 0666, value);
    while(*c != '\0'){
        fputc(*c, stderr);
        c++;
        sleep(rand() % 2 + 1);
    }
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");
    return 0;
}