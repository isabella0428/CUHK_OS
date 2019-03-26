/*mom_sol.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char * argv[])
{
    sem_t *sema;
    int fd;
    int value = 1;
    sema = sem_open("sema", O_CREAT, 0666, value);
    printf("Mom comes home\n");
    sem_wait(sema);
    printf("Mom checks the fridge\n");
    fd = open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd, 0, SEEK_END) == 0){
        printf("Mom goes to buy milk\n");
        if(lseek(fd, 0, SEEK_END) == 5){
            printf("Mom: What a waste of money!\n");
        }
        else{
            write(fd, "milk ", 5);
            printf("Mom puts the milk into the fridge and leaves.\n");
        }
    }
    else{
        printf("Mom checks the fridge and leaves\n");
    }
    close(fd);
    sem_post(sema);
    sem_close(sema);
    sem_unlink(sema);
}