#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct args{
    char *name;
    int age;
};

void *hello(void * input){
    printf("name: %s\n", ((struct args*)input)->name);
    printf("age: %d\n", ((struct args*)input)->age);
    pthread_exit(NULL);
}

int main(int args, char *argv[]){
    struct args * Allen = (struct args*)malloc(sizeof(struct args));
    char allen[] = "Allen";
    Allen->name = allen;
    Allen->age = 20;

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *) Allen);
    pthread_join(tid, NULL);
    return 0;
}