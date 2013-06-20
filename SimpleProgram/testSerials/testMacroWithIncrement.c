#include <stdio.h>

#define SQUARE(x) ((x) * (x))

void test(int x)
{
    int y = SQUARE(x);

    printf("Result of ((x++) * (x++)):x=d% is: %d\n",x, y);
}

int main()
{
    int x = 5;

    test(x);
    test(x);

    return 0;
}
