/**
 * testConvertIntToString.cpp -- Test conversion from int to string.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-09 [Friday, 221]
 *
 * Build:
 *   g++ testConvertIntToString.cpp -o testConvertIntToString
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string resultCode(uint32_t rc)
{
    string rcStr;
    // rcStr = to_string(rc);// "to_string" is added in C++11
    stringstream tmp;
    tmp << "0x" << hex << rc;
    rcStr = tmp.str();

    switch(rc) {
    case 0x2001:
        rcStr.append(" (OK)");
        break;
    case 0x2002:
        rcStr.append(" (General Error)");
        break;
    case 0x2003:
        rcStr.append(" (Session Not Open)");
        break;
    case 0x2005:
        rcStr.append(" (Operation Not Supported)");
        break;
    default:
        break;
    }
    return rcStr;
}

int main()
{
    cout << resultCode(0x2001) << endl;

    string tmp = "abcdefg";
    const unsigned char* a = (const unsigned char *) tmp.c_str();
    cout << a << endl;

    return 0;
}
