/*dad_sol.c*/
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
    printf("Dad comes home\n");
    sleep(2);
    sem_wait(sema);
    printf("Dad checks the fridge\n");
    fd = open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd, 0, SEEK_END) == 0){
        printf("Dad goes to buy milk\n");
        sleep(2);
        if(lseek(fd, 0, SEEK_END) == 5){
            printf("Dad: What a waste of money!\n");
        }
        else{
            write(fd, "milk ", 5);
            printf("Dad puts the milk into the fridge and leaves.\n");
        }
    }
    else{
        printf("Dad checks the fridge and leaves");
    }
    close(fd);
    sem_post(sema);
    sem_close(sema);
    sem_unlink(sema);
}