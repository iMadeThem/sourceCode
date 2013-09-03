/**
 * ObjectSlicing.cpp -- Demo of object slicing by passing objects by value.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-03 [Tuesday, 246]
 *
 * Build:
 *   g++ ObjectSlicing.cpp -o ObjectSlicing
 */

#include <iostream>
#include <string>

using namespace std;

class Pet {
    string pname;
    public:
        Pet(const string& name) : pname(name) {}
        virtual string name() const { return pname; }
        virtual string description() const {
            return "This is " + pname;
        }
};

class Dog : public Pet {
    string favoriteActivity;
    public:
        Dog(const string& name, const string& activity) : Pet(name), favoriteActivity(activity) {}
        string description() const {
            return Pet::name() + " likes to " + favoriteActivity;
        }
};
void describe(Pet p) { // Slices the object
    cout << p.description() << endl;
}

void describe2(Pet& p) { // pass by reference
    cout << p.description() << endl;
}

int main() {
    Pet p("Alfred");
    Dog d("Fluffy", "sleep");
    describe(p);
    describe(d);

    describe2(p);
    describe2(d);

    return 0;
} ///:~

/* Output:
   This is Alfred
   This is Fluffy
   This is Alfred
   Fluffy likes to sleep
 */
