/**
 * ByteTest.cpp -- Member override operator test cases.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-15 [Thursday, 227]
 *
 * Build:
 *   g++ ByteTest.cpp -o ByteTest
 */

#include "Byte.h"
#include <iostream>

using namespace std;
ofstream out("ByteTest.out.txt");

void k(Byte& b1, Byte& b2) {
    b1 = b1 * b2 + b2 % b1;

#define TRY2(OP)                                \
    out << "b1 = ";  b1.print(out);             \
    out << ", b2 = "; b2.print(out);            \
    out << "; b1 " #OP " b2 produces ";            \
    (b1 OP b2).print(out);                  \
    out << endl;

    b1 = 9;
    b2 = 47;

    TRY2(+) TRY2(-) TRY2(*) TRY2(/)
    TRY2(%) TRY2(^) TRY2(&) TRY2(|)
    TRY2(<<) TRY2(>>) TRY2( += ) TRY2( -= )
    TRY2( *= ) TRY2( /= ) TRY2( %= ) TRY2( ^= )
    TRY2( &= ) TRY2( |= ) TRY2( >>= ) TRY2( <<= )
    TRY2( = ) // Assignment operator

    // Conditionals:
#define TRYC2(OP)                               \
    out << "b1 = "; b1.print(out);          \
    out << ", b2 = "; b2.print(out);        \
    out << "; b1 " #OP " b2 produces ";        \
    out << (b1 OP b2);                  \
    out << endl;

    b1 = 9;
    b2 = 47;

    TRYC2(<) TRYC2(>) TRYC2(==) TRYC2(!=) TRYC2(<=) TRYC2(>=) TRYC2(&&) TRYC2(||)
    // Chained assignment:
    Byte b3 = 92;

    b1 = b2 = b3;
}

int main()
{
    out << "member functions:" << endl;
    Byte b1(47), b2(9);
    k(b1, b2);

    return 0;
} ///:~
