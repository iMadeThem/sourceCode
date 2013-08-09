/**
 * StaticVariablesInFunctions.cpp -- Static variables in functions.
 * This realization is very vulnerable to multithreading problems.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-09 [Friday, 221]
 */

#include "require.h"
#include <iostream>

using namespace std;

char oneChar(const char* charArray = 0)
{
    static const char* s;
    if(charArray) {
        s = charArray;
        cout << "Initialization" << endl;
        return *s;
    } else {
        require(s, "un-initialized s");
    }
    if(*s == '\0')
        return 0;
    return *s++;
}

const char* a = "abcdefghijklmnopqrstuvwxyz";

int main(int argc, char* argv[])
{
    // oneChar(); // require() fails
    oneChar(a);
    // Initializes s to a
    char c;

    // while((c = oneChar(a)) != 0) // !! Dead loop
    while((c = oneChar(a)) != 0)
        cout << c << endl;
    return 0;
} ///:~
