#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{ 
    char *env[] = {"LS_COLORS=fi=04;33;44",NULL}; 
    printf("Using *execle* to exec ls -l\n"); 
    execle("/bin/ls","ls","-l","--color",NULL,env); 
    printf("Program Terminated\n");
    return 0;
}