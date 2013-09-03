/**
 * TestInheritance.cpp -- Test inheritance.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-29 [Thursday, 241]
 *
 * Build:
 *   g++ TestInheritance.cpp -o TestInheritance
 */

#include <iostream>

using namespace std;

class A {
    public:
        A() {
            cout << "A()" << endl;
        }
};

class B {
    public:
        B() {
            cout << "B()" << endl;
        }
};

class C : public A {
    B b;
    public:
        // No default constructor
};

int main(int argc, char* argv[])
{
    C c;

    return 0;
} ///:~

/* Output:
   A()
   B()
 */
