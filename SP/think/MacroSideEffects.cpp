/**
 * MacroSideEffects.cpp -- Test macro side effects.
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-06 [Tuesday, 218]
 *
 * g++ MacroSideEffects.cpp require.h -o MacroSideEffects
 */

#include "require.h"
#include <iostream>
#include <fstream>

using namespace std;

#define BAND(x) (((x) > 5 && (x) < 10) ? (x) : 0)

int main(int argc, char* argv[])
{
    ofstream out("macro_side.out");
    assure(out, "macro_side.out");
    for(int i = 4; i < 11; i++) {
        int a = i;
        out << "a = " << a << endl << '\t';
        // the following line will cause three increments
        out << "BAND(++a)=" << BAND(++a) << endl;
        out << "\t a = " << a << endl;
    }
    return 0;
}
