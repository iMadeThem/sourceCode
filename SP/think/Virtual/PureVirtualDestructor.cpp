/**
 * PureVirtualDestructor.cpp -- Pure virtual destructors require a function body.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 *
 * Build:
 *   g++ PureVirtualDestructor.cpp -o PureVirtualDestructor
 */

#include <iostream>

using namespace std;

class Pet {
    public:
        virtual ~Pet() = 0;
};

Pet::~Pet() {
    cout << "~Pet()" << endl;
}

class Dog : public Pet {
    public:
        ~Dog() {
            cout << "~Dog()" << endl;
        }
};

int main() {
    Pet* p = new Dog; // Upcast
    delete p; // Virtual destructor call

    return 0;
} ///:~

/* Output:
   ~Dog()
   ~Pet()
 */
