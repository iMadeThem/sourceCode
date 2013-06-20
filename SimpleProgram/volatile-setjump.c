#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void f(void);

static jmp_buf env;

int main(void)
{
    int val = -1;
//    int x;     // volatile が必要
    volatile int x;     // volatile が必要

    x = 3;
    if((val = setjmp(env)) != 0) {
	printf("val = %d (x = %d)\n", val, x);
	exit(0);
    }

    x = 5;
    printf("val = %d (x = %d)\n", val, x);
    f();

    exit(0);
}

void f(void)
{
    longjmp(env, 1);
}
