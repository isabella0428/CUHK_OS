#include <pthread.h>
#include <stdio.h>

void * hello(void *input){
    printf("%s\n", (char *)input);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_create(&tid, NULL, hello, "Hello, world!");
    pthread_join(tid, NULL);
    return 0;
}