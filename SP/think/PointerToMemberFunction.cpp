/**
 * PointerToMemberFunction.cpp -- Pointer to member function demo.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-14 [Wednesday, 226]
 *
 * Build:
 *   g++ PointerToMemberFunction.cpp -o PointerToMemberFunction
 */

#include <iostream>

using namespace std;

class Widget {
    public:
        void f(int) const {
            cout << "Widget::f()\n";
        }

        void g(int) const {
            cout << "Widget::g()\n";
        }

        void h(int) const {
            cout << "Widget::h()\n";
        }

        void i(int) const {
            cout << "Widget::i()\n";
        }
};

int main(int argc, char* argv[])
{
    Widget w;
    Widget* wp = &w;
    void (Widget::*pmem)(int) const = &Widget::h;
    (w.*pmem)(1);
    (wp->*pmem)(2);

    return 0;
} ///:~
