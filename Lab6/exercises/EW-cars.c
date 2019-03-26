/*EW-cars.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
int main(int argc, char * argv[])
{   
    sem_t *mutex;
    mutex = sem_open("mutex", O_CREAT, 0666, 1);
    sem_wait(mutex);
    int i,car=0, loop=3;
    for(i=0;i<loop;i++){
        printf("Semaphore: The road from east to west is open\n");
        sleep(rand()%2+1);
        printf("EW-Car: car %d passed\n",car++);
    }
    printf("EW: Time is up. %d cars passed.\n",car);
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");
    return 0;
}