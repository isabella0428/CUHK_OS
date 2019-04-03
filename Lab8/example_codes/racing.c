#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NITERS 10000000
void *count (void *arg);
unsigned int cnt = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, count, NULL);
    pthread_create(&tid2, NULL, count, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("cnt:%d\n",cnt);
}

void *count(void *argv){
    int i = 0;
    while(i < NITERS)
    {   
        pthread_mutex_lock(&mutex);
        cnt += 1;
        i++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}