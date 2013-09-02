/**
 * VirtualObjectSize.cpp -- Object sizes with/without virtual functions.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-01 [Sunday, 244]
 *
 * Build:
 *   g++ VirtualObjectSize.cpp -o VirtualObjectSize
 */

#include <iostream>

using namespace std;

class NoVirtual {
    int a;

    public:
        void x() const {}

        int i() const {
            return 1;
        }
};

class OneVirtual {
    int a;

    public:
        virtual void x() const {}

        int i() const {
            return 1;
        }
};

class TwoVirtuals {
    int a;
    public:
        virtual void x() const {}
        virtual int i() const {
            return 1;
        }
};

class NoVirtualNoMember {
    public:
        void x() const {}

        int i() const {
            return 1;
        }
};

class OneVirtualNoMember {
    public:
        virtual void x() const {}

        int i() const {
            return 1;
        }
};

class TwoVirtualsNoMember {
    public:
        virtual void x() const {}
        virtual int i() const {
            return 1;
        }
};

int main(int argc, char* argv[])
{
    cout << "int: " << sizeof(int) << endl;
    cout << "NoVirtual: " <<
    sizeof(NoVirtual) << endl;
    cout << "void* : " << sizeof(void*) << endl;
    cout << "OneVirtual: " <<
    sizeof(OneVirtual) << endl;
    cout << "TwoVirtuals: " <<
    sizeof(TwoVirtuals) << endl;

    cout << "int: " << sizeof(int) << endl;
    cout << "NoVirtual: " <<
    sizeof(NoVirtualNoMember) << endl;
    cout << "void* : " << sizeof(void*) << endl;
    cout << "OneVirtual: " <<
    sizeof(OneVirtualNoMember) << endl;
    cout << "TwoVirtuals: " <<
    sizeof(TwoVirtualsNoMember) << endl;

    return 0;
} ///:~

/* Output:
   int: 4
   NoVirtual: 4
   void* : 8
   OneVirtual: 16
   TwoVirtuals: 16
   int: 4
   NoVirtual: 1
   void* : 8
   OneVirtual: 8
   TwoVirtuals: 8
 */
