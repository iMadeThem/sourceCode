/**
 * OverloadingOperatorComma.cpp -- operator,
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-15 [Thursday, 227]
 *
 * Build:
 *   g++ OverloadingOperatorComma.cpp -o OverloadingOperatorComma
 */

#include <iostream>

using namespace std;

class After {
    public:
        const After& operator,(const After&) const {
            cout << "After::operator,()" << endl;
            return *this;
        }
};

class Before {};

Before& operator,(int, Before& b)
{
    cout << "Before::operator,()" << endl;
    return b;
}

int main()
{
    After a, b;
    a, b;
    // Operator comma called
    // After::operator,()

    Before c;
    1, c;
    // Operator comma called
    // Before::operator,()

    return 0;
} ///:~
