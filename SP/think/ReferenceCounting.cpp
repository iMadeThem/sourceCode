/**
 * ReferenceCounting.cpp -- Object reference count.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-20 [Tuesday, 232]
 *
 * Build:
 *   g++ ReferenceCounting.cpp -o ReferenceCounting
 */

#include "require.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ofstream out("ReferenceCounting.out.txt");

class Dog {
    string nm;
    int refcount;
    Dog(const string& name) : nm(name), refcount(1) {
        out << "Creating Dog: " << *this << endl;
    }

    // Prevent assignment:
    Dog& operator=(const Dog& rv);

    public:
        // Dogs can only be created on the heap:
        static Dog* make(const string& name) {
            return new Dog(name);
        }

        Dog(const Dog& d) : nm(d.nm + " copy"), refcount(1) {
            out << "Dog copy-constructor: " << *this << endl;
        }

        ~Dog() {
            out << "Deleting Dog: " << *this << endl;
        }

        void attach() {
            ++refcount;
            out << "Attached Dog: " << *this << endl;
        }

        void detach() {
            require(refcount != 0);
            out << "Detaching Dog: " << *this << endl;
            // Destroy object if no one is using it:
            if(--refcount == 0) delete this;
        }

        // Conditionally copy this Dog.
        // Call before modifying the Dog, assign
        // resulting pointer to your Dog*.
        Dog* unalias() {
            out << "Unaliasing Dog: " << *this << endl;
            // Don't duplicate if not aliased:
            if(refcount == 1) return this;
            --refcount;
            // Use copy-constructor to duplicate:
            return new Dog(*this);
        }

        void rename(const string& newName) {
            nm = newName;
            out << "Dog renamed to: " << *this << endl;
        }

        friend ostream& operator<<(ostream& os, const Dog& d) {
            return os << "[" << d.nm << "], rc = " << d.refcount;
        }
};

class DogHouse {
    Dog* p;
    string houseName;

    public:
        DogHouse(Dog* dog, const string& house) : p(dog), houseName(house) {
            out << "Created DogHouse: " << *this << endl;
        }

        DogHouse(const DogHouse& dh) : p(dh.p), houseName("copy-constructed " + dh.houseName) {
            p->attach();
            out << "DogHouse copy-constructor: " << *this << endl;
        }

        DogHouse& operator=(const DogHouse& dh) {
            // Check for self-assignment:
            if(&dh != this) {
                houseName = dh.houseName + " assigned";
                // Clean up what you're using first:
                p->detach();
                p = dh.p;
                // Like copy-constructor
                p->attach();
            }

            out << "DogHouse operator= : " << *this << endl;
            return *this;
        }

        // Decrement refcount, conditionally destroy
        ~DogHouse() {
            out << "DogHouse destructor: " << *this << endl;
            p->detach();
        }

        void renameHouse(const string& newName) {
            houseName = newName;
        }

        void unalias() {
            p = p->unalias();
        }

        // Copy-on-write. Anytime you modify the contents of the pointer you must
        // first unalias it:
        void renameDog(const string& newName) {
            unalias();
            p->rename(newName);
        }

        // ... or when you allow someone else access:
        Dog* getDog() {
            unalias();
            return p;
        }

        friend ostream& operator<<(ostream& os, const DogHouse& dh) {
            return os << "[" << dh.houseName << "] contains " << *dh.p;
        }
};

int main()
{
    DogHouse fidos(Dog::make("Fido"), "FidoHouse"),
    spots(Dog::make("Spot"), "SpotHouse");
    out << "Entering copy-construction" << endl;
    DogHouse bobs(fidos);
    out << "After copy-constructing bobs" << endl;
    out << "fidos:" << fidos << endl;
    out << "spots:" << spots << endl;
    out << "bobs:" << bobs << endl;
    out << "Entering spots = fidos" << endl;
    spots = fidos;
    out << "After spots = fidos" << endl;
    out << "spots:" << spots << endl;
    out << "Entering self-assignment" << endl;
    bobs = bobs;
    out << "After self-assignment" << endl;
    out << "bobs:" << bobs << endl;

    // Comment out the following lines:
    out << "Entering rename(\"Bob\")" << endl;
    bobs.getDog()->rename("Bob");
    out << "After rename(\"Bob\")" << endl;
    return 0;
} ///:~
