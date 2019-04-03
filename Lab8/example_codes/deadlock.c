#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *Allen(void *arg);
void *Bob(void *arg);
pthread_mutex_t book1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t book2 = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, Allen, NULL);
    pthread_create(&tid2, NULL, Bob, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}

void * Allen(void *arg){
    pthread_mutex_lock(&book1);
    sleep(10);
    pthread_mutex_lock(&book2);
    printf("Allen got all the books and is going to do homework!");
    pthread_mutex_unlock(&book1);
    pthread_mutex_unlock(&book2);
}

void * Bob(void *arg){
    pthread_mutex_lock(&book2);
    sleep(10);
    pthread_mutex_lock(&book1);
    printf("Bob got all the books and is going to do homework!");
    pthread_mutex_unlock(&book2);
    pthread_mutex_unlock(&book1);
}