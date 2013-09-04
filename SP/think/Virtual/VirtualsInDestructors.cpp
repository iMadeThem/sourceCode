/**
 * VirtualsInDestructors.cpp -- Virtual calls inside destructors.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 *
 * Build:
 *   g++ VirtualsInDestructors.cpp -o VirtualsInDestructors
 */

#include <iostream>

using namespace std;

class Base {
    public:
        virtual ~Base() {
            cout << "~Base()\n";
            f();
        }
        virtual void f() { cout << "Base::f()\n"; }
};

class Derived : public Base {
    public:
        ~Derived() { cout << "~Derived()\n"; }
        void f() { cout << "Derived::f()\n"; }
};

int main() {
    Base* bp = new Derived; // Upcast
    delete bp;

    return 0;
} ///:~

/* Output:
   ~Derived()
   ~Base()
   Base::f()
 */
