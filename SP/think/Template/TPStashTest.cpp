/**
 * TPStashTest.cpp -- TPStash test case.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-12 [Thursday, 255]
 *
 * Build:
 *   g++ TPStashTest.cpp AutoCounter.cpp -o TPStashTest
 */

#include "AutoCounter.h"
#include "TPStash.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    PStash<AutoCounter> acStash;
    for(int i = 0; i < 10; i++)
        acStash.add(AutoCounter::create());

    cout << "Removing 5 manually:" << endl;
    for(int j = 0; j < 5; j++)
        delete acStash.remove(j);

    cout << "Remove two without deleting them:" << endl;
    // ... to generate the cleanup error message.
    cout << acStash.remove(5) << endl;
    cout << acStash.remove(6) << endl;
    cout << "The destructor cleans up the rest:" << endl;

    // Repeat the test from earlier chapters:
    ifstream in("TPStashTest.cpp");
    assure(in, "TPStashTest.cpp");
    PStash<string> stringStash;
    string line;
    while(getline(in, line))
        stringStash.add(new string(line));
    // Print out the strings:
    for(int u = 0; stringStash[u]; u++)
        cout << "stringStash[" << u << "] = " << *stringStash[u] << endl;

    return 0;
} ///:~
