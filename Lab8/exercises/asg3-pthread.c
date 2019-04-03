/* Header Declaration */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


/* Function Declaration */
extern int *readdata(char *filename, int *number);

// A comparator function used by qsort 
    int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 

int *readdata(char *filename, int *number){
    FILE *fp;
    fp = fopen(filename, "r"); // read mode
    fscanf(fp,"%d\n",number);
    printf("number is %d\n", *number);
    int * ret = (int *) malloc( sizeof(int)* (*number));
    for(int i = 0; i < *number; i++){
        fscanf(fp, "%d", &ret[i]);
    }
    fclose(fp);
    return ret;
}



/* Main */

int main(int argc, char *argv[]) {
    if(argc!=5) {
        printf("usage:\n");
        printf("    ./asg3-pthread inputfile1 inputfile2 outputfile ThreadNum\n");

        return -1;
    }

    int *array1, *array2;
    int num1, num2;

    array1 = readdata(argv[1], &num1);
    
    array2 = readdata(argv[2], &num2);

    /* do your assignment start from here */
    if(num1 == 0 || num2 == 0){
        printf("Input file(s) empty!");
    }


    // initialize by yourself, this array will be used to output your result
    int *ret = (int *) malloc(sizeof(int)* (num1));
    int cnt = 0;            // the length of res, will be used to output your result
    qsort(array1, num1, sizeof(int), compare);
    qsort(array2, num2, sizeof(int), compare);
    int n = 0;

    for(int m = 0; m < num1; m ++){
        if(n >= num2){
            break;
        }
        while(1){
            if(array1[m] == array2[n])
            {   if(cnt == 0 || array1[m] != ret[cnt - 1])
                {
                    ret[cnt] = array1[m];
                    cnt ++;
                }
                break;
            }
            n++;
            if(array2[n] > array1[m])
                break;
        }
    }
    
    FILE * of;
    of = fopen(argv[3], "w");
    for(int n = 0; n < cnt; n++){
        fprintf(of,"%d\n",ret[n]);
    }
    
    // op=fopen(argv[3], "r");
    // /* you should call "output(fp, res, len)" to output your result*/
    // output(op, ret, cnt);
    fclose(of);

    return 0;
}
