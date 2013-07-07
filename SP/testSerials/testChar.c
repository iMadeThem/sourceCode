/**
 * testChar.c -- Test the size of char and 'c'.
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-03 [Wednesday, 184]
 */

#include <stdio.h>
#include <stdlib.h>

#define p(x) printf("%s\n", x)

int main(int argc, char* argv[])
{
    printf("%ld\n",sizeof(char));
    // 1
    printf("%ld\n",sizeof('a'));
    // 4

/*    char *command;
    printf("Enter a Command: ");
    // we have to allocate memory to contain input strings, or use a fixed array.
    scanf("%s",command);  // Segmentation fault: 11
*/

/*
    char* prefix = '+';  // Illegal
    //  incompatible integer to pointer conversion initializing 'char *' with an
    // expression of type 'int' [-Wint-conversion]
*/

    char *prefix = (char*)malloc(2);
    *prefix = '+';
    *(prefix+1) = 0;
    printf("size: %ld, content: %s\n", sizeof(prefix), prefix);
    free(prefix);

    p("---Test differece between signed and unsigned char pointer");
    unsigned char *uc;
    char *c;
    unsigned char v = 128; // maximum of unsigned char
    uc = &v;
    c  = &v;

    if (*uc != *c)
        printf("there is difference\n");

    printf("char*c = %d\n", *c);
    printf("unsigned char*uc = %d\n", *uc);

    return 0;

}
