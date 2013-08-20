/**
 * PointerToMemberOperator.cpp -- Pointer to member operator ->*  .
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-19 [Monday, 231]
 *
 * Build:
 *   g++ PointerToMemberOperator.cpp -o PointerToMemberOperator
 */

#include <iostream>

using namespace std;

class Dog {
    public:
        int run(int i) const {
            cout << "run\n";
            return i;
        }

        int eat(int i) const {
            cout << "eat\n";
            return i;
        }

        int sleep(int i) const {
            cout << "ZZZ\n";
            return i;
        }

        typedef int (Dog::*PMF)(int) const;

        // operator->* must return an object
        // that has an operator():
        class FunctionObject {
            Dog* ptr;
            PMF pmem;

            public:
                // Save the object pointer and member pointer
                FunctionObject(Dog* wp, PMF pmf) : ptr(wp), pmem(pmf) {
                    cout << "FunctionObject constructor\n";
                }

                // Make the call using the object pointer
                // and member pointer
                int operator()(int i) const {
                    cout << "FunctionObject::operator()\n";
                    return (ptr->*pmem)(i);
                    // Make the call
                }
        };

        FunctionObject operator->*(PMF pmf) {
            cout << "operator->*" << endl;
            return FunctionObject(this, pmf);
        }
};

int main()
{
    Dog w;
    Dog::PMF pmf = &Dog::run;
    cout << (w->*pmf)(1) << endl;
    pmf = &Dog::sleep;
    cout << (w->*pmf)(2) << endl;
    pmf = &Dog::eat;
    cout << (w->*pmf)(3) << endl;

    return 0;
} ///:~

/*
   operator->*
   FunctionObject constructor
   FunctionObject::operator()
   run
   1
   operator->*
   FunctionObject constructor
   FunctionObject::operator()
   ZZZ
   2
   operator->*
   FunctionObject constructor
   FunctionObject::operator()
   eat
   3
 */