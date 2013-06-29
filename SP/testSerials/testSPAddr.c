/**
 * testSPAddr.c -- Test stack pointer address
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-06-29 [Saturday, 180]
 */

#include <stdio.h>

float average(int *arr, int size)
{
    int sum;
    int dummy;


    printf("arr: %p\n",&arr);
    printf("size: %p\n",&size);
    printf("sum: %p\n",&sum);
    printf("dummy: %p\n",&dummy);

    for(int i=0; i<size; i++) {
        sum += arr[i];
    }
    return (sum * 1.0f) / size;
}


int main(int argc, char* argv[])
{
    int array[] = { 1, 3, 4, 6, 7};

    average(array, sizeof(array)/sizeof(array[0]));

    return 0;
}
