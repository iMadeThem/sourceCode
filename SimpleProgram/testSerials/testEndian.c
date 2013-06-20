#include <stdio.h>

int main()
{
    printf("Judge endian by pointer\n");

    int x = 1;
    if(*(char *)&x == 1)
    {
        printf("...Little endian\n");
    } else {
        printf("...Big endian\n");
    }

    printf("Judge endian by union\n");
    union
    {
        int i;
        char c[sizeof(int)];
    } y;
    y.i = 1;
    if(y.c[0] == 1)
    {
        printf("...Little endian\n");
    } else {
        printf("...Big endian\n");
    }

    return 0;
}
