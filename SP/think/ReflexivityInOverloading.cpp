/**
 * ReflexivityInOverloading.cpp -- Reflexivity in overloading by using global overloaded operator.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-21 [Wednesday, 233]
 *
 * Build:
 *   g++ ReflexivityInOverloading.cpp -o ReflexivityInOverloading
 */

#include <iostream>

using namespace std;

class Number {
    int i;

    public:
        Number(int ii = 0) : i(ii) {}

        const Number operator+(const Number& n) const {
            return Number(i + n.i);
        }
        friend const Number operator-(const Number&, const Number&);
        friend ostream& operator<<(ostream&, const Number&);
};

const Number operator-(const Number& n1, const Number& n2)
{
    return Number(n1.i - n2.i);
}

ostream& operator<<(ostream& out, const Number& num)
{
    out << num.i;
    return out;
}

int main(int argc, char* argv[])
{
    Number a(47), b(11);

    cout << a + b << endl; // OK, 58
    cout << a + 1 << endl; // 2nd arg converted to Number, 48
    //! 1 + a; // Wrong! 1st arg not of type Number
    cout << a - b << endl; // OK, 36
    cout << a - 1 << endl; // 2nd arg converted to Number, 46
    cout << 1 - a << endl; // 1st arg converted to Number, -46

    return 0;
} ///:~
