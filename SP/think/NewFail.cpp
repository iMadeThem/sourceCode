/**
 * NewFail.cpp -- Demo of the storage allocation in new fails.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-24 [Saturday, 236]
 *
 * Build:
 *   g++ NewFail.cpp -o NewFail
 */

#include <iostream>
#include <new> // bad_alloc definition

using namespace std;

class NoMemory {
    public:
        NoMemory() {
            cout << "NoMemory::NoMemory()" << endl;
        }

        void* operator new(size_t sz) throw(bad_alloc) {
            cout << "NoMemory::operator new" << endl;
            throw bad_alloc();
            // "Out of memory"
        }
};

int main()
{
    NoMemory* nm = 0;

    try {
        nm = new NoMemory;
    }catch(bad_alloc) {
        cerr << "Out of memory exception" << endl;
    }
    cout << "nm = " << nm << endl;

    return 0;

} ///:~

/* Output:
   NoMemory::operator new
   Out of memory exception
   nm = 0
 */
