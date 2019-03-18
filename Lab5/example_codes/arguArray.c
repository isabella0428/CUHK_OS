#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{ 
    char **argList = (char**) malloc(sizeof(char*) * 3); 
    argList[0] = (char*)malloc(sizeof(char) * 10);     
    strcpy(argList[0],"ls"); 
    argList[1] = (char*)malloc(sizeof(char) * 10);     
    strcpy(argList[1],"-al"); 
    argList[2] = NULL;

    execvp(*argList,argList);
   return 0;
}