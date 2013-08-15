/**
 * Linenum.cpp -- Add line number to any file at the beginning.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-14 [Wednesday, 226]
 *
 * Build:
 *   g++ Linenum.cpp -o Linenum
 */

#include "require.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
    requireArgs(argc, 1, "Usage: Linenum file\n"
                "Adds line numbers to file");
    ifstream in(argv[1]);
    assure(in, argv[1]);

    string line;
    vector<string> lines;

    while(getline(in, line)) // Read in entire file
        lines.push_back(line);
    if(lines.size() == 0) return 0;

    int num = 0;
    // Number of lines in file determines width:
    const int width = int(log10(lines.size())) + 1;
    for(int i = 0; i < lines.size(); i++) {
        cout.setf(ios::right, ios::adjustfield);
        cout.width(width);
        cout.fill('0');
        cout << ++num << ") " << lines[i] << endl;
    }

    return 0;
} ///:~