/**
 * IntegerTest.cpp -- Integer class test cases.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-15 [Thursday, 227]
 *
 * Build:
 *   g++ IntegerTest.cpp Integer.cpp Integer.h ../require.h -o IntegerTest
 */

//{L} Integer
#include "Integer.h"
#include <fstream>
using namespace std;

ofstream out("IntegerTest.out.txt");

void h(Integer& c1, Integer& c2)
{
    // A complex expression:
    c1 += c1 * c2 + c2 % c1;

#define TRY(OP)                                 \
    out << "c1 = "; c1.print(out);               \
    out << ", c2 = "; c2.print(out);            \
    out << "; c1 " #OP " c2 produces ";           \
    (c1 OP c2).print(out);                  \
    out << endl;

    TRY(+) TRY(-) TRY(*) TRY(/)
    TRY(%) TRY(^) TRY(&) TRY(|)
    TRY(<<) TRY(>>) TRY( += ) TRY( -= )
    TRY( *= ) TRY( /= ) TRY( %= ) TRY( ^= )
    TRY( &= ) TRY( |= ) TRY( >>= ) TRY( <<= )

    // Conditionals:
#define TRYC(OP) \
    out << "c1 = "; c1.print(out);          \
    out << ", c2 = "; c2.print(out);        \
    out << "; c1 " #OP " c2produces ";        \
    out << (c1 OP c2);                  \
    out << endl;

    TRYC(<) TRYC(>) TRYC(==) TRYC(!=) TRYC(<=)
    TRYC(>=) TRYC(&&) TRYC(||)
}

int main()
{
    cout << "friend functions" << endl;
    Integer c1(47), c2(9);
    out << "Test case 1----------" << endl;
    h(c1, c2);
    out << "Test case 2----------" << endl;
    Integer c3(2), c4(-3);
    h(c3, c4);
    out << "Test case 3----------" << endl;
    for(int i = 0; i < 4; i++) {
        out << "(8 << -" << i << ") = " << (8 << -i) << endl;
        out << "-" << i << " >> 2) = " << (-i >> 2) << endl;
    }

    return 0;
} ///:~
