/**
 * ObjectCount.cpp -- Count how many objects exist.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-13 [Tuesday, 225]
 *
 * Build:
 *   g++ ObjectCount.cpp -o ObjectCount
 */

#include <fstream>
#include <string>

using namespace std;

ofstream out("ObjectCount.out.txt");

class ObjectCount {
    static int objectCount;
    public:
        ObjectCount() {
            objectCount++;
        }

        static void print(const string& msg = "") {
            if(msg.size() != 0) out << msg << ": ";
            out << "objectCount = " <<
            objectCount << endl;
        }

        ~ObjectCount() {
            objectCount--;
            print("~ObjectCount()");
        }
};

int ObjectCount::objectCount = 0;

// Pass and return BY VALUE:
ObjectCount f(ObjectCount x)
{
    x.print("x argument inside f()");
    return x;
}

int main()
{
    ObjectCount h;
    ObjectCount::print("after construction of h");
    ObjectCount h2 = f(h);
    ObjectCount::print("after call to f()");
} ///:~

/**
 * output:
 * after construction of h: objectCount = 1
 * x argument inside f(): objectCount = 1
 * ~ObjectCount(): objectCount = 0
 * after call to f(): objectCount = 0
 * ~ObjectCount(): objectCount = -1
 * ~ObjectCount(): objectCount = -2
 */
