/**
 * ObjectCountCopyctor.cpp -- Count how many objects exist.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-13 [Tuesday, 225]
 *
 * Build:
 *   g++ ObjectCountCopyctor.cpp -o ObjectCountCopyctor
 */

#include <fstream>
#include <string>

using namespace std;

ofstream out("ObjectCountCopyctor.out.txt");

class ObjectCountCopyctor {
    static int objectCount;
    string name; // object identifier

    public:
        ObjectCountCopyctor(const string& id = "") : name(id) {
            ++objectCount;
            print("ObjectCountCopyctor()");
        }

        // The copy-constructor:
        ObjectCountCopyctor(const ObjectCountCopyctor& h) : name(h.name) {
            name += " copy";
            ++objectCount;
            print("ObjectCountCopyctor(const ObjectCountCopyctor&)");
        }

        void print(const string& msg = "") {
            if(msg.size() != 0) out << msg << endl;
            out << '\t' << name << ": " << "objectCount = " <<
            objectCount << endl;
        }

        ~ObjectCountCopyctor() {
            --objectCount;
            print("~ObjectCountCopyctor()");
        }
};

int ObjectCountCopyctor::objectCount = 0;

// Pass and return BY VALUE:
ObjectCountCopyctor f(ObjectCountCopyctor x)
{
    x.print("x argument inside f()");
    out << "Returning from f()" << endl;
    return x;
}

int main()
{
    ObjectCountCopyctor h("h");
    out << "Entering f()" << endl;
    ObjectCountCopyctor h2 = f(h);
    h2.print("h2 after call to f()");
    out << "Call f(), no return value" << endl;
    f(h);
    out << "After call to f()" << endl;

    return 0;
} ///:~

/**
 * output:
   ObjectCountCopyctor()
   h: objectCount = 1
   Entering f()
   ObjectCountCopyctor(const ObjectCountCopyctor&)
   h copy: objectCount = 2
   x argument inside f()
   h copy: objectCount = 2
   Returning from f()
   ObjectCountCopyctor(const ObjectCountCopyctor&)
   h copy copy: objectCount = 3
   ~ObjectCountCopyctor()
   h copy: objectCount = 2
   h2 after call to f()
   h copy copy: objectCount = 2
   Call f(), no return value
   ObjectCountCopyctor(const ObjectCountCopyctor&)
   h copy: objectCount = 3
   x argument inside f()
   h copy: objectCount = 3
   Returning from f()
   ObjectCountCopyctor(const ObjectCountCopyctor&)
   h copy copy: objectCount = 4
   ~ObjectCountCopyctor()
   h copy copy: objectCount = 3
   ~ObjectCountCopyctor()
   h copy: objectCount = 2
   After call to f()
   ~ObjectCountCopyctor()
   h copy copy: objectCount = 1
   ~ObjectCountCopyctor()
   h: objectCount = 0
 */
