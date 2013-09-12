/**
 * StaticHierarchyNavigation.cpp -- Navigating class hierarchies with static_cast.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-06 [Friday, 249]
 *
 * Build:
 *   g++ StaticHierarchyNavigation.cpp -o StaticHierarchyNavigation
 */

#include <iostream>
#include <typeinfo>

using namespace std;

class Shape {
    public:
        virtual ~Shape() {};
};

class Circle : public Shape {};

class Square : public Shape {};

class Other {};

int main() {
    Circle c;
    Shape* s = &c; // Upcast: normal and OK
    // More explicit but unnecessary:
    s = static_cast<Shape*>(&c);
    // (Since upcasting is such a safe and common
    // operation, the cast becomes cluttering)
    Circle* cp = 0;
    Square* sp = 0;
    // Static Navigation of class hierarchies
    // requires extra type information:

    // with RTTI check, static_cast is actually the same as dynamic_cast
    if(typeid(s) == typeid(cp)) { // C++ RTTI
        cout << "down casting Shape to Circle" << endl;
        cp = static_cast<Circle*>(s);
    }
    // cp = static_cast<Circle*>(s);  // this works as well
    cout << "After trying casting Shape to Circle, returned: " << cp << endl;
    // 0

    if(typeid(s) == typeid(sp)) {
        cout << "down casting Shape to Square" << endl;
        sp = static_cast<Square*>(s);
    }
    // sp = static_cast<Square*>(s); // this works as well
    cout << "After trying casting Shape to Square, returned: " << sp << endl;
    // 0

    if(cp != 0)
        cout << "It's a circle!" << endl;
    if(sp != 0)
        cout << "It's a square!" << endl;
    // Static navigation is ONLY an efficiency hack;
    // dynamic_cast is always safer. However:
    // Other* op = static_cast<Other*>(s);
    // Conveniently gives an error message, while
    Other* op2 = (Other *) s;
    // does not

    return 0;
} ///:~
