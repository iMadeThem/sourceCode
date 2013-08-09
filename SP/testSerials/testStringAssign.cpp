/**
 * testStringAssign.cpp -- Test String's assign method.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-08 [Thursday, 220]
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    string tmp;
    unsigned short* aa = new unsigned short[4];
    aa[0] = 1;
    aa[1] = 2;
    aa[2] = 3;
    aa[3] = 4;

    ostringstream out;
    out << hex << aa;
    cout << out.str() << endl;
    // 0x7f90c8c000e0
    //    uint32_t a = 1234;
    //    tmp.assign(a);
    //    cout << tmp << endl;

    return 0;
} ///:~
