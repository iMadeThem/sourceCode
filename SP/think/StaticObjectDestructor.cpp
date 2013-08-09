/**
 * StaticObjectDestructor.cpp -- To trace static objects's destructors.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-09 [Friday, 221]
 *
 * Build:
 *  g++ StaticVariablesInFunctions.cpp require.h -o StaticVariablesInFunctions
 */

#include <fstream>

using namespace std;
ofstream LOG("StaticObjectDestructor.log.txt"); // trace log

class Obj {
    char c;
    // Identifier
    public:
        Obj(char cc) : c(cc) {
            LOG << "Obj::Obj() for " << c << endl;
        }

        ~Obj() {
            LOG << "Obj::~Obj() for " << c << endl;
        }
};

// Global (static storage)
// Constructor & destructor always called
Obj a('a');

void f()
{
    static Obj b('b');
}

void g()
{
    static Obj c('c');
}

int main(int argc, char* argv[])
{
    LOG << "inside main()" << endl;

    f();
    // Calls static constructor for b
    // g() not called
    LOG << "leaving main()" << endl;

    return 0;
} ///:~

// OUTPUT:
// Obj::Obj() for a
// inside main()
// Obj::Obj() for b
// leaving main()
// Obj::~Obj() for b
// Obj::~Obj() for a
