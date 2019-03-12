/* This file is meant to test 
how the preprocesser works */

#include "header.h"


int main(void)  {
    add_fun(1, 2);
    return 0;
}

/* The pre-processor expand the code form header file
 and put it in code before compilation.*/
 
/* 
# 1 "include.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 361 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "include.c" 2
# 1 "./header.h" 1
int add_fun(int a, int b) {
        return (a + b);
}
# 2 "include.c" 2


int main(void) {
    add_fun(1, 2);
    return 0;
}
*/