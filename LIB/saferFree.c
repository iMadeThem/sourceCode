/**
 * saferFree.c -- This is a safer free() wrapper function.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-06-29 [Saturday, 180]
 */

#include <stdio.h>
#include <stdlib.h>

void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}
#define safeFree(p) saferFree((void**)&(p))

int main(int argc, char* argv[])
{
    int *pi;
    pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("Before: %p\n",pi);
// Before: 0x7fa5c9c000e0

    safeFree(pi);
    printf("After: %p\n",pi);
    safeFree(pi);  // multiple free would cause no error
// After: 0x0

    return 0;
}
