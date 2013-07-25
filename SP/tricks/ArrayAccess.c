/**
 * ArrayAccess.c -- A tricky way of accessing array element.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-25 [Thursday, 206]
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    printf("0[arr] = %d\n", 0[arr]);
    // 1
    printf("1[arr] = %d\n", 1[arr]);
    // 2
    /*
     * warning: array index 7 is past the end of the array (which contains 7 elements) [-Warray-bounds]
     */
    printf("7[arr] = %d\n", 7[arr]);
    // 0
    return 0;
}
