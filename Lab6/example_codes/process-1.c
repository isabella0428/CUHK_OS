/*process-1.c*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <sys/stat.h>
// #include <semaphore.h>
// #include <unistd.h>

// int main(int argc, char *argv[]){
//     sem_t *mutex;
//     int fd;
//     int value = 1;
//     mutex = sem_open("mutex", O_CREAT, 0666, value);
//     char *c = "This is CSCI3150 -- An Operating System course!\n";
//     sem_wait(mutex);
//     setbuf(stderr, NULL);
//     while(*c != '\n'){
//         fputs(*c, stderr);
//         c ++;
//         sleep(1);
//     }
//     sem_post(mutex);
//     sem_close(mutex);
//     sem_unlink("mutex");
//     return 0;
// }


/*process-1.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
int main(int argc, char * argv[]) {
       sem_t * mutex;
       char * c = "This is CSCI3150--An operating system course.\n";
    // specify no buffering for stderr
    setbuf(stderr, NULL);
       mutex = sem_open("mutex_for_stderr", O_CREAT, 0666, 1);
       sem_wait(mutex);
       while (* c != '\0') {
            fputc(* c, stderr);
            c++;
            sleep(1);
         }
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex_for_stderr");
    return 0;
}