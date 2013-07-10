/**
 * testCalc.c -- Test a function.
 *
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-10 [Wednesday, 191]
 *
 * http://stackoverflow.com/questions/5666762/java-imposible-puzzler
 * n^(n+1) + n^n + ... n^1 + n^0
 */

#include <stdio.h>
#include <stdlib.h>

int count = 0;
void calc(int n, int p)
{
    count++;
    if(p > n)
        return;
    for(int i = 0; i < n; i++)
        calc(n, p + 1);
}

int main(int argc, char* argv[])
{

    if(argc != 2) {
        printf("Provide an integer!");
        return 0;
    }
    int num = strtol(argv[1], NULL, 10);

    calc(num, 0);
    printf("Counter: %d\n", count);

    return 0;
}
