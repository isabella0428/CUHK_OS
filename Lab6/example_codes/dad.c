#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int fd;
    printf("Dad comes home.\n");
    sleep(5);
    printf("Dad checks the fridge.\n");
    fd=open("fridge.txt", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd,0,SEEK_END)==0){
        printf("Dad goes to buy milk...\n");
        sleep(2);
        if(lseek(fd,0,SEEK_END) == 0)
        {
            write(fd,"milk ",5);
            printf("Dad puts milk in fridge and leaves.\n");
        }
        else{
            printf("What a waste of food! The fridge can not hold so much milk!\n");
        }
    }else{
        printf("Dad closes the fridge and leaves.\n");
    }
    close(fd);
    return 0;
}