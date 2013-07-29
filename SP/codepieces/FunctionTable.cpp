/**
 * FunctionTable.cpp -- Function table of CPP.
 * Author: Leon (leon(at)gmail.com)
 * Date  : 2013-07-28 [Sunday, 209]
 */

#include <iostream>

using namespace std;

// A macro to define dummy functions:
#define DF(N) void N() { \
        cout << "... function " #N " called ..." << endl; }
DF(a);
DF(b);
DF(c);
DF(d);
DF(e);
DF(f);
DF(g);

void (*func_table[])() =
{
    a, b, c, d, e, f, g
};

int main(int argc, char* argv[])
{
    while(1) {
        cout << "press a key from 'a' to 'g' "
        "or q to quit" << endl;

        char c, cr;

        cin.get(c);
        cin.get(cr); // second one for CR
        if( c == 'q' )
            break; // ... out of while(1)
        if( c < 'a' || c > 'g' )
            continue;
        (*func_table[c - 'a'])();
    }

    return 0;
}
