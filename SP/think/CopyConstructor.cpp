/**
 * CopyConstructor.cpp -- Correctly synthesizing the copy-constructor by compiler.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-28 [Wednesday, 240]
 *
 * Build:
 *   g++ CopyConstructor.cpp -o CopyConstructor
 */

#include <iostream>

using namespace std;

class Parent {
    int i;

    public:
        Parent(int ii) : i(ii) {
            cout << "Parent(int ii)\n";
        }

        Parent(const Parent& b) : i(b.i) {
            cout << "Parent(const Parent&)\n";
        }

        Parent() : i(0) {
            cout << "Parent()\n";
        }

        friend ostream& operator<<(ostream& os, const Parent& b) {
            return os << "Parent: " << b.i << endl;
        }
};

class Member {
    int i;

    public:
        Member(int ii) : i(ii) {
            cout << "Member(int ii)\n";
        }

        Member(const Member& m) : i(m.i) {
            cout << "Member(const Member&)\n";
        }

        friend ostream& operator<<(ostream& os, const Member& m) {
            return os << "Member: " << m.i << endl;
        }

};

class Child : public Parent {
    int i;
    Member m;

    public:
        Child(int ii) : Parent(ii), i(ii), m(ii) {
            cout << "Child(int ii)\n";
        }

        friend ostream& operator<<(ostream& os, const Child& c) {
            return os << (Parent&) c << c.m << "Child: " << c.i << endl;
        }
};

int main()
{
    Child c(2);
    cout << "calling copy-constructor: " << endl;
    Child c2 = c;
    // Calls copy-constructor
    cout << "values in c2:\n" << c2;

    return 0;
} ///:~

/* Output:
   Parent(int ii)
   Member(int ii)
   Child(int ii)
   calling copy-constructor:
   Parent(const Parent&)
   Member(const Member&)
   values in c2:
   Parent: 2
   Member: 2
   Child: 2
 */
