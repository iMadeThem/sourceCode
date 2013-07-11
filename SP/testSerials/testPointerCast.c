/**
 * testPonterCastErr.c -- Test the error case when casting pointer to different type.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-10 [Wednesday, 191]
 *
 * modifiers' meaning
 *
 * hh  signed char*, unsigned char*
 * h   short int*, unsigned short
 * l   long int*, unsigned long int*
 * ll  long long int*, unsigned long long int*
 * j   intmax_t*, uintmax_t*
 * z   size_t*, size_t*
 * t   ptrdiff_t*
 * L   long double*
 *
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    int  num = 2147483647;
    int *pi = &num;
    short *ps = (short *) pi;

    printf("pi: %p  signed value(16:x): %x  signed value(10:d): %d\n", pi, *pi, *pi);
    //pi: 0x7fff683aff4c  signed value(16:x): 7fffffff  signed value(10:d): 2147483647

    /* The following line will cause compile warning
       // warning: format specifies type 'unsigned short' but the argument has type 'int' [-Wformat]
       //printf("pi: %p  signed value(16:hx): %hx  signed value(10:hd): %hd\n", pi, *pi, *pi);
       //pi: 0x7fff683aff4c  signed value(16:hx): ffff  signed value(10:hd): -1
     */

    printf("ps: %p  unsigned value(16:hx): %hx  unsigned value(10:hd): %hd\n",
           ps, (unsigned short) *ps, (unsigned short) *ps);
    //ps: 0x7fff683aff4c  unsigned value(16:hx): ffff  unsigned value(10:hd): -1
    printf("ps: %p  unsigned value(16:x): %x  unsigned value(10:d): %d\n",
           ps, (unsigned short) *ps, (unsigned short) *ps);
    //ps: 0x7fff683aff4c  unsigned value(16:x): ffff  unsigned value(10:d): 65535
    printf("ps: %p  signed value(16:x): %x  signed value(10:d): %d\n", ps, (signed short) *ps,
           (signed short) *ps);
    //ps: 0x7fff683aff4c  signed value(16:x): ffffffff  signed value(10:d): -1
    printf("ps: %p  signed value(16:hx): %hx  signed value(10:hd): %hd\n", ps, (signed short) *ps,
           (signed short) *ps);
    //ps: 0x7fff683aff4c  signed value(16:hx): ffff  signed value(10:hd): -1

    return 0;
}
