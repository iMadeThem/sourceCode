/**
 * PlacementOperatorNew.cpp -- Placement with operator new.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-24 [Saturday, 236]
 *
 * Build:
 *   g++ PlacementOperatorNew.cpp -o PlacementOperatorNew
 */

#include <cstddef> // Size_t
#include <iostream>

using namespace std;

class X {
    int i;

    public:
        X(int ii = 0) : i(ii) {
            cout << "this = " << this << endl;
        }

        ~X() {
            cout << "X::~X(): " << this << endl;
        }

        void* operator new(size_t, void* loc) {
            return loc;
        }
};

int main(int argc, char* argv[])
{
    int l[10];
    cout << "l = " << l << endl;
    X* xp = new(l) X(47); // X at location l
    xp->X::~X(); // Explicit destructor call
    // ONLY use with placement!
    return 0;
} ///:~

/* Output:
   l = 0x7fff5d61a9e8
   this = 0x7fff5d61a9e8
   X::~X(): 0x7fff5d61a9e8
 */
