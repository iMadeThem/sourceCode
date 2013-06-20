#include <stdio.h>

int hasStaticInt(int i)
{
    static int x = 0;
    x += i;
    return x;
}

void test()
{
    int sum = 0;
    for (int i = 0; i <= 4; i++){
        sum += hasStaticInt(i);
    }
    printf("Result of sum is: %d\n", sum);
}

int main()
{
    test();
    return 0;
}
