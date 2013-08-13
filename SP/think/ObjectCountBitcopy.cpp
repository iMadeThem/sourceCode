/**
 * ObjectCountBitcopy.cpp -- Count how many objects exist by bitcopying.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-13 [Tuesday, 225]
 *
 * Build:
 *   g++ ObjectCountBitcopy.cpp -o ObjectCountBitcopy
 */

#include <fstream>
#include <string>

using namespace std;

ofstream out("ObjectCountBitcopy.out.txt");

class ObjectCountBitcopy {
    static int objectCount;
    public:
        ObjectCountBitcopy() {
            objectCount++;
        }

        static void print(const string& msg = "") {
            if(msg.size() != 0) out << msg << ": ";
            out << "objectCount = " <<
            objectCount << endl;
        }

        ~ObjectCountBitcopy() {
            objectCount--;
            print("~ObjectCountBitcopy()");
        }
};

int ObjectCountBitcopy::objectCount = 0;

// Pass and return BY VALUE:
ObjectCountBitcopy f(ObjectCountBitcopy x)
{
    x.print("x argument inside f()");
    return x;
}

int main()
{
    ObjectCountBitcopy h;
    ObjectCountBitcopy::print("after construction of h");
    ObjectCountBitcopy h2 = f(h);
    ObjectCountBitcopy::print("after call to f()");
} ///:~

/**
 * output:
 * after construction of h: objectCount = 1
 * x argument inside f(): objectCount = 1
 * ~ObjectCountBitcopy(): objectCount = 0
 * after call to f(): objectCount = 0
 * ~ObjectCountBitcopy(): objectCount = -1
 * ~ObjectCountBitcopy(): objectCount = -2
 */
