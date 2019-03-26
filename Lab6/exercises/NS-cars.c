/* north-south car */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

int main(int agrc, char *argv[]){
    sem_t *mutex;
    int i, car=0, loop=3;
    mutex = sem_open("mutex", O_CREAT, 0666, 1);
    sem_wait(mutex);
    for(i=0;i<loop;i++){
        printf("Semaphore: The road from north to south is open\n");
        sleep(1);
        printf("NS-Car: car %d passed\n",car++);
    }
    printf("NS: Time is up. %d cars passed.\n",car);
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex");
    return 0;
}