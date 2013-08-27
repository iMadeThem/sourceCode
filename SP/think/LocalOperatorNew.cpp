/**
 * LocalOperatorNew.cpp -- Overload new in class, locally.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-23 [Friday, 235]
 *
 * Build:
 *   g++ LocalOperatorNew.cpp -o LocalOperatorNew
 */

#include <cstddef> // Size_t
#include <fstream>
#include <iostream>
#include <new>

using namespace std;
ofstream out("LocalOperatorNew.out.txt");

class LocalOperatorNew {
    enum {sz = 10};
    char c[sz];
    // To take up space, not used
    static unsigned char pool[];
    static bool alloc_map[];

    public:
        enum { psize = 100}; // frami allowed
        LocalOperatorNew() {
            out << "LocalOperatorNew()\n";
        }
        ~LocalOperatorNew() {
            out << "~LocalOperatorNew() ... ";
        }
        void* operator new(size_t) throw(bad_alloc);
        void operator delete(void*);
};

unsigned char LocalOperatorNew::pool[psize * sizeof(LocalOperatorNew)];
bool LocalOperatorNew::alloc_map[psize] = {false};

// Size is ignored -- assume a LocalOperatorNew object
void* LocalOperatorNew::operator new(size_t) throw(bad_alloc)
{
    for(int i = 0; i < psize; i++)
        if(!alloc_map[i]) {
            out << "using block " << i << " ... ";
            alloc_map[i] = true; // Mark it used
            return pool + (i * sizeof(LocalOperatorNew));
        }

    out << "out of memory" << endl;
    throw bad_alloc();
}

void LocalOperatorNew::operator delete(void* m)
{
    if(!m) return;
    // Check for null pointer
    // Assume it was created in the pool
    // Calculate which block number it is:
    unsigned long block = (unsigned long) m - (unsigned long) pool;
    block /= sizeof(LocalOperatorNew);
    out << "freeing block " << block << endl;
    // Mark it free:
    alloc_map[block] = false;
}

int main()
{
    LocalOperatorNew* f[LocalOperatorNew::psize];
    try {
        for(int i = 0; i < LocalOperatorNew::psize; i++)
            f[i] = new LocalOperatorNew;
        new LocalOperatorNew;
        // Out of memory
    }catch(bad_alloc)  {
        cerr << "Out of memory!" << endl;
    }

    delete f[10];
    f[10] = 0; // Use released memory:
    LocalOperatorNew* x = new LocalOperatorNew;

    for(int j = 0; j < LocalOperatorNew::psize; j++)
        delete f[j]; // Delete f[10] OK
}
///:~
