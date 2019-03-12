/* This file is meant to test 
how shared memory is dynamically linked */

#include <stdio.h>
int main(int argc, char *argv[])
{
    float v = 3.14;
    printf("sin(3.14) is %f\n", sin(v));
    return 0;
}

/* 
Without linking it to the shared library, it will report mistakes.
Run : gcc math.c -lm
It will run

Run: ldd a.out
to show which shared libraries are dynamically linked.
*/