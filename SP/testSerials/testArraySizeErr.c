/**
 * testArraySizeErr.c -- Test Calculating the Array Size Incorrectly, cause unexpected result.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-10 [Wednesday, 191]
 */

#include <stdio.h>
#include <string.h> /* strcpy */

#define NUL '\0'   /* No standard headers defines NUL */

void replace(char buffer[], char replacement, size_t size)
{
    size_t count = 0;
    while(*buffer != NUL && count++ < size) {
        *buffer = replacement;
        buffer++;
    }
}

int main(int argc, char* argv[])
{
    /* strcpy will check buffer size whether it can hold the target string
     * so if size of name[] is less than string's length, runtime error happens
     * Abort trap: 6
     */
    char name[8]; /* Abort trap: 6 : indicating a failed assertion */
    strcpy(name, "Alexander");
    replace(name, '+', sizeof(name));
    printf("%s\n", name);

    return 0;
}
