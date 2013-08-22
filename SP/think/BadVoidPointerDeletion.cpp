/**
 * BadVoidPointerDeletion.cpp -- Delete void pointer will not call destructor.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-22 [Thursday, 234]
 *
 * Build:
 *   g++ BadVoidPointerDeletion.cpp -o BadVoidPointerDeletion
 */

#include <iostream>

using namespace std;

class Object {
    void* data; // Some storage
    const int size;
    const char id;

    public:
        Object(int sz, char c) : size(sz), id(c) {
            data = new char[size];
            cout << "Constructing object " << id << ", size = " << size << endl;
        }

        ~Object() {
            cout << "Destructing object " << id << endl;
            delete[]data;
            // OK, just releases storage,
            // no destructor calls are necessary
        }
};

int main(int argc, char* argv[])
{
    Object* a = new Object(40, 'a');
    delete a;
    void* b = new Object(40, 'b');
    delete b;

    return 0;
} ///:~

/* Output:
   Constructing object a, size = 40
   Destructing object a
   Constructing object b, size = 40
 */
