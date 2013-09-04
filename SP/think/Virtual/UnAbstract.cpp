/**
 * UnAbstract.cpp -- Pure virtual destructors seem to behave strangely.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 *
 * Build:
 *   g++ UnAbstract.cpp -o UnAbstract
 */

#include <iostream>

using namespace std;

class AbstractBase {
    public:
        virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase {};

// No overriding of destructor necessary?
int main() {
    Derived d;

    return 0;
} ///:~
