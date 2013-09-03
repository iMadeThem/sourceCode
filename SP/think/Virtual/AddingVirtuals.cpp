/**
 * AddingVirtuals.cpp -- Adding virtuals in derivation.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-03 [Tuesday, 246]
 *
 * Build:
 *   g++ AddingVirtuals.cpp -o AddingVirtuals
 */

#include <iostream>
#include <string>

using namespace std;

class Pet {
    string pname;
    public:
        Pet(const string& petName) : pname(petName) {}
        // This is not pure virtual function, then inline definition is legal
        virtual string name() const { return pname; }
        virtual string speak() const { return ""; }
};

class Dog : public Pet {
    string name;
    public:
        Dog(const string& petName) : Pet(petName) {}
        // New virtual function in the Dog class:
        virtual string sit() const {
            return Pet::name() + " sits";
        }
        string speak() const { // Override
            return Pet::name() + " says 'Bark!'";
        }
};

int main() {
    Pet* p[] = {
        new Pet("generic"),
        new Dog("bob")
    };
    cout << "p[0]->speak() = " <<
    p[0]->speak() << endl;
    cout << "p[1]->speak() = " <<
    p[1]->speak() << endl;
    //! cout << "p[1]->sit() = "
    //!      << p[1]->sit() << endl; // Illegal
    //! compile error:
    //! error: ‘class Pet’ has no member named ‘sit’
    cout << "p[1]->sit() = " << ((Dog *) p[1])->sit()  << endl;

    return 0;
} ///:~

/* Output:
   p[0]->speak() =
   p[1]->speak() = bob says 'Bark!'
   p[1]->sit() = bob sits
 */
