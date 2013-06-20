#include <stdio.h>

int f(void) {
    return -1;
}

int main () {

    printf("!-1 = %d\n", !-1);
    printf("!(-1)f() = %d\n", !f());
    printf("!0 = %d\n", !0);
    printf("!100 = %d\n", !100);

    signed char b = 127;
    printf("  signed char b(127) = %d, b+1 = %d, b+2 = %d\n", b, b+1, (signed char)b+2);

    signed char c = 128;
    printf("  signed char c(128) = %d, c+1 = %d, c-1 = %d\n", c, c+1, c-1);

    unsigned char d = 128;
    printf("unsigned char d(128) = %d, d+1 = %d\n", d, d+1);

    unsigned char e = 255;
    printf("unsigned char e(255) = %d, e+1 = %d, e+2 = %d\n", e, e+1, e+2);
    return 0;
}
