/**
 * testPointerParam.c -- Test pointer as parameter.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-06-29 [Saturday, 180]
 */

#include <stdio.h>
#include <stdlib.h>

// right usage
void allocateArray_r(int **arr, int size, int value)
{
    *arr = (int*)malloc(size * sizeof(int));
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            *(*arr+i) = value;
        }
    }
}

// wrong usage
void allocateArray_w(int *arr, int size, int value)
{
    arr = (int*)malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
//            printf("arr[i]=%d\n", arr[i]);
        }
    }
}


int main(int argc, char* argv[])
{
    int *vector_r = NULL;
    int *vector_w = NULL;
// when pointer is passed, it is passed by value
    allocateArray_r(&vector_r,5,45);
    printf("%p\n",vector_r);
    free(vector_r);
// 0x7fa0b1403bb0

/*
When the program is executed you will see 0x0 displayed because when vector_w is
passed to the function, its value is copied into the parameter arr (which means
passed by value). Modifying arr has no effect on vector_w
*/
    allocateArray_w(vector_w,5,45);
    printf("%p\n",vector_w);
    free(vector_w);
// 0x0

    return 0;
}
