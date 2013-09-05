/**
 * OStackTest.cpp -- OStack test case.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 *
 * Build:
 *   g++ OStackTest.cpp OStack.h ../require.h -o OStackTest
 */

#include "OStack.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Use multiple inheritance. We want
// both a string and an Object:
class MyString : public string, public Object {
    public:
        ~MyString() {
            cout << "deleting string: " << *this << endl;
        }
        MyString(string s) : string(s) {}
};

int main(int argc, char* argv[]) {
    requireArgs(argc, 1); // File name is argument

    ifstream in(argv[1]);
    assure(in, argv[1]);

    Stack textlines;
    string line;
    // Read file and store lines in the stack:
    while(getline(in, line))
        textlines.push(new MyString(line));
    // Pop some lines from the stack:
    MyString* s;
    for(int i = 0; i < 10; i++) {
        if((s = (MyString *) textlines.pop()) == 0)
            break;
        cout << *s << endl;
        delete s;
    }
    cout << "Letting the destructor do the rest:" << endl;

    return 0;
} ///:~

/* Output: $ ./OStackTest OStackTest.txt
   20
   deleting string: 20
   ~Object()
   19
   deleting string: 19
   ~Object()
   18
   deleting string: 18
   ~Object()
   17
   deleting string: 17
   ~Object()
   16
   deleting string: 16
   ~Object()
   15
   deleting string: 15
   ~Object()
   14
   deleting string: 14
   ~Object()
   13
   deleting string: 13
   ~Object()
   12
   deleting string: 12
   ~Object()
   11
   deleting string: 11
   ~Object()
   Letting the destructor do the rest:
   ~Stack() enter
   ~Stack()
   deleting string: 10
   ~Object()
   ~Stack()
   deleting string: 9
   ~Object()
   ~Stack()
   deleting string: 8
   ~Object()
   ~Stack()
   deleting string: 7
   ~Object()
   ~Stack()
   deleting string: 6
   ~Object()
   ~Stack()
   deleting string: 5
   ~Object()
   ~Stack()
   deleting string: 4
   ~Object()
   ~Stack()
   deleting string: 3
   ~Object()
   ~Stack()
   deleting string: 2
   ~Object()
   ~Stack()
   deleting string: 1
   ~Object()
 */
