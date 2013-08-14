/**
 * DefaultCopyConstructor.cpp -- Test default copy constructor with composition class.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-14 [Wednesday, 226]
 *
 * Build:
 *   g++ DefaultCopyConstructor.cpp -o DefaultCopyConstructor
 */

#include <iostream>
#include <string>

using namespace std;

class WithCC {
    // With copy-constructor
    public:
        // Explicit default constructor required:
        WithCC() {}

        WithCC(const WithCC&) {
            cout << "WithCC(WithCC&)" << endl;
        }
};

class WoCC {
    // Without copy-constructor
    string id;

    public:
        WoCC(const string& ident = "") : id(ident) {}

        void print(const string& msg = "") const {
            if(msg.size() != 0) cout << msg << ": ";
            cout << id << endl;
        }
};

class Composite {
    WithCC withcc;
    // Embedded objects
    WoCC wocc;

    public:
        Composite() : wocc("Composite()") {}

        void print(const string& msg = "") const {
            wocc.print(msg);
        }
};

int main(int argc, char* argv[])
{
    Composite c;
    c.print("Contents of c");
    cout << "Calling Composite copy-constructor" << endl;
    Composite c2 = c;
    // Calls copy-constructor
    c2.print("Contents of c2");

    return 0;
} ///:~

/*
 * Output:
   Contents of c: Composite()
   Calling Composite copy-constructor
   WithCC(WithCC&)
   Contents of c2: Composite()
 */
