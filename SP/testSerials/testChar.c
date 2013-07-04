/**
 * testChar.c -- Test the size of char and 'c'.
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-03 [Wednesday, 184]
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%ld\n",sizeof(char));
    // 1
    printf("%ld\n",sizeof('a'));
    // 4
    return 0;
}
