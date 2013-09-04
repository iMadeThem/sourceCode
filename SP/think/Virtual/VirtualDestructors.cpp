/**
 * VirtualDestructors.cpp -- Behavior of virtual vs. non-virtual destructor.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-04 [Wednesday, 247]
 *
 * Build:
 *   g++ VirtualDestructors.cpp -o VirtualDestructors
 */

#include <iostream>

using namespace std;

class Base1 {
    public:
        ~Base1() { cout << "~Base1()\n"; }
};

class Derived1 : public Base1 {
    public:
        ~Derived1() { cout << "~Derived1()\n"; }
};

class Base2 {
    public:
        virtual ~Base2() { cout << "~Base2()\n"; }
};

class Derived2 : public Base2 {
    public:
        ~Derived2() { cout << "~Derived2()\n"; }
};

int main() {
    Base1* bp = new Derived1; // Upcast
    delete bp;
    Base2* b2p = new Derived2; // Upcast
    delete b2p;

    return 0;
} ///:~

/* Output:
   ~Base1()
   ~Derived2()
   ~Base2()
 */
