/**
 * testFormatStringAttack.c -- Test for Format String Attack.
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-10 [Wednesday, 191]
 */

/*
 * attack test
 *
 *
 * ./testFormatStringAttack "%x %x %x %x"
 * buffer (28): 0 687c55a8 687c5428 687c53e0
 * x is 1/0x1 (@ 0x7fff687c536c)
 *
 * ./testFormatStringAttack "aaaa %x %x"
 * buffer (15): aaaa 0 688815a8
 * x is 1/0x1 (@ 0x7fff6888136c)
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char buf[100];

    int x;

    if(argc != 2)
        return 1;
    x = 1;

    snprintf(buf, sizeof(buf), argv[1]);
    buf[sizeof(buf) - 1] = 0;

    printf("buffer (%ld): %s\n", strlen(buf), buf);
    printf("x is %d/%#x (@ %p)\n", x, x, &x);

    return 0;
}
