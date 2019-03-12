/* This file is meant to test gcc -E command
to find out how pre-processor works */

#include <stdio.h>
#define SWAP(a, b) { int c; c = a; a = b; b = c;}

int main(void) {
    int i = 10, j = 20;
    printf("before swap: i = %d, j = %d\n", i, j);
    SWAP(i, j);
    printf("after swap: i = %d, j = %d\n", i, j);
    return 0;
}

/* function is replaced by pre-processor */
/* 
    int main(void) {
        int i = 10, j = 20;
        printf("before swap: i = %d, j = %d\n", i, j);
        { int c; c = i; i = j; j = c;};
        printf("after swap: i = %d, j = %d\n", i, j);
        return 0;
}
*/