/**
 * testFuncNesting.c -- Test function nesting.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-06 [Tuesday, 218]
 *
 * Standard C and C++ do not support nested functions, but: GCC supports nested
 * functions in C, as a language extension.
 *
 * gcc -fnested-functions testFuncNesting.c -o testFuncNesting
 */

#include <stdio.h>

void f() {
    printf("In func f()\n");

    void g() {
        printf("In func g(), which is defined in func f()\n");
        //f(); //dead loop
    }

    printf("Exited defination of g(), back in f()\n");

    g();
}

int main(int argc, char* argv[])
{
    f();
    //g(); //cannot call here

    return 0;
}

/* OUTPUT:
 * In func f()
 * Exited defination of g(), back in f()
 * In func g(), which is defined in func f()
 */
