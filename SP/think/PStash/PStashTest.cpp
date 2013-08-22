/**
 * PStashTest.cpp -- Test class.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-22 [Thursday, 234]
 *
 * Build:
 *   g++ PStashTest.cpp PStash.cpp PStash.h -o PStashTest
 */

#include "PStash.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    PStash intStash;

    // 'new' works with built-in types, too. Note the "pseudo-constructor"
    // syntax:
    for(int i = 0; i < 25; i++)
        intStash.add(new int(i));

    for(int j = 0; j < intStash.count(); j++)
        cout << "intStash[" << j << "] = " << *(int *) intStash[j] << endl;

    // Clean up:
    for(int k = 0; k < intStash.count(); k++)
        // no cast is necessary because there’s no destructor for an int and all
        // we need is memory release
        // warning: deleting ‘void*’ is undefined
        delete intStash.remove(k);

    ifstream in ("PStashTest.cpp");
    assure(in, "PStashTest.cpp");
    PStash stringStash;
    string line;
    while(getline(in, line))
        stringStash.add(new string(line));

    // Print out the strings:
    for(int u = 0; stringStash[u]; u++)
        cout << "stringStash[" << u << "] = " << *(string *) stringStash[u] << endl;

    // Clean up:
    for(int v = 0; v < stringStash.count(); v++)
        // for the stringpointers, if you forget to do the cast you’ll have
        // another (quiet) memory leak, so the cast is essential
        delete (string *) stringStash.remove(v);

    return 0;
} ///:~
