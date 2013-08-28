/**
 * OrderOfCDxstructor.cpp -- Constructor/destructor order.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-25 [Sunday, 237]
 *
 * Build:
 *   g++ OrderOfCDxstructor.cpp -o OrderOfCDxstructor
 */

#include <iostream>
#include <fstream>

using namespace std;

ofstream out("OrderOfCDxstructor.out.txt");

#define CLASS(ID) class ID {                    \
        public:                                     \
            ID(int) { out << #ID " constructor\n"; }     \
            ~ID() { out << #ID " destructor\n"; }        \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
    Member1 m1;
    Member2 m2;
    public:
        Derived1(int) : m2(1), m1(2), Base1(3) {
            out << "Derived1 constructor\n";
        }

        ~Derived1() {
            out << "Derived1 destructor\n";
        }
};

class Derived2 : public Derived1 {
    Member3 m3;
    Member4 m4;

    public:
        Derived2() : m3(1), Derived1(2), m4(3) {
            out << "Derived2 constructor\n";
        }
        ~Derived2() {
            out << "Derived2 destructor\n";
        }
};

int main()
{

    Derived2 d2;

    return 0;
} ///:~

/* Output:
   Base1 constructor
   Member1 constructor
   Member2 constructor
   Derived1 constructor
   Member3 constructor
   Member4 constructor
   Derived2 constructor
   Derived2 destructor
   Member4 destructor
   Member3 destructor
   Derived1 destructor
   Member2 destructor
   Member1 destructor
   Base1 destructor
 */
