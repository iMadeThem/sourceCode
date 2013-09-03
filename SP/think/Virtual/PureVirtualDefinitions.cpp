/**
 * PureVirtualDefinitions.cpp -- Pure virtual base definitions.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-03 [Tuesday, 246]
 *
 * Build:
 *   g++ PureVirtualDefinitions.cpp -o PureVirtualDefinitions
 */

#include <iostream>

using namespace std;

class Pet {
    public:
        virtual void speak() const = 0;
        virtual void eat() const = 0;
        // Inline pure virtual definitions illegal:
        //!  virtual void sleep() const = 0 {}
};
// OK, not defined inline
void Pet::eat() const {
    cout << "Pet::eat()" << endl;
}

void Pet::speak() const {
    cout << "Pet::speak()" << endl;
}

class Dog : public Pet {
    public:
        // Use the common Pet code:
        void speak() const { Pet::speak(); }
        void eat() const { Pet::eat(); }
};
int main(int argc, char* argv[])
{
    Dog simba;  // Richard's dog
    simba.speak();
    simba.eat();

    return 0;
} ///:~

/* Output:
   Pet::speak()
   Pet::eat()
 */
