/**
 * Time.cpp -- Time test class.
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-06 [Tuesday, 218]
 *
 * g++ Time.cpp Time.h -o Time
 */

#include <iostream>
#include "Time.h"

using namespace std;

int main(int argc, char* argv[])
{
    Time start;

    for(int i = 1; i < 1000; i++) {
        cout << i << ' ';
        if(i % 10 == 0) cout << endl;
    }

    Time end;

    cout << endl;
    cout << "start = " << start.ascii();
    cout << "end = " << end.ascii();
    cout << "delta = " << end.delta(&start) << endl;
    cout << "delta(ms) = " << end.deltaMilli(&start) << endl;

    return 0;
}
