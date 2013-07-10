/**
 * testStructPointerComp.c -- Test the Pointer Arithmetic and Structures, which will not guaranteed to work properly.
 *
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-10 [Wednesday, 191]
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    typedef struct _item
    {
        int partNumber;
        int quantity;
        int binNumber;
    }Item;

    /* pointer arithmetic should be avoided */
    Item part = {12345, 35, 107};
    int *pi = &part.partNumber;
    printf("Part number: %d\n", *pi);

    pi++;
    printf("Quantity: %d\n", *pi);

    pi++;
    printf("Bin number: %d\n", *pi);

    return 0;
}
