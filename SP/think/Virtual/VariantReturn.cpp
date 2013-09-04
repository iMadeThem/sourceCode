/**
 * VariantReturn.cpp -- Returning a pointer or reference to a derived type
 * during overriding.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-04 [Wednesday, 247]
 *
 * Build:
 *   g++ VariantReturn.cpp -o VariantReturn
 */

#include <iostream>
#include <string>

using namespace std;

class PetFood {
    public:
        virtual string foodType() const = 0;
};

class Pet {
    public:
        virtual string type() const = 0;
        virtual PetFood* eats() = 0;
};

class Bird : public Pet {
    public:
        string type() const { return "Bird"; }
        class BirdFood : public PetFood {
            public:
                string foodType() const {
                    return "Bird food";
                }
        };
        // Upcast to base type:
        PetFood* eats() { return &bf; }
    private:
        BirdFood bf;
};

class Cat : public Pet {
    public:
        string type() const { return "Cat"; }
        class CatFood : public PetFood {
            public:
                string foodType() const { return "Birds"; }
        };
        // Return exact type instead:
        CatFood* eats() { return &cf; }
    private:
        CatFood cf;
};

int main() {
    Bird b;
    Cat c;
    Pet* p[] = { &b, &c, };
    for(int i = 0; i < sizeof p / sizeof *p; i++)
        cout << p[i]->type() << " eats " <<
        p[i]->eats()->foodType() << endl;
    /* Output:
       Bird eats Bird food
       Cat eats Birds
     */
    // Can return the exact type:
    Cat::CatFood* cf = c.eats();
    Bird::BirdFood* bf;
    // Cannot return the exact type:
    //! bf = b.eats();
    // error: invalid conversion from ‘PetFood*’ to ‘Bird::BirdFood*’
    // Must downcast:
    bf = dynamic_cast<Bird::BirdFood*>(b.eats());

    return 0;
} ///:~
