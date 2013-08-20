/**
 * OperatorOverloadingConversion.cpp -- Operator conversion.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-20 [Tuesday, 232]
 *
 * Build:
 *   g++ OperatorOverloadingConversion.cpp -o OperatorOverloadingConversion
 */

#include <iostream>

using namespace std;

class Three {
    int i;

    public:
        Three(int ii = 0, int = 0) : i(ii) {
            cout << "Three(" << i << ")" << endl;
        }
};

class Four {
    int x;

    public:
        Four(int xx) : x(xx) {
            cout << "Constructor of Four()" << endl;
        }

        operator Three() const {
            cout << "operator Three() in Four" << endl;

            return Three(x);
        }
};

void g(Three)
{
    cout << "in g(Three)" << endl;
}

int main()
{
    Four four(1);
    g(four);
    g(1); // Calls Three(1,0)

    return 0;
} ///:~

/* Output:
   Constructor of Four()
   operator Three() in Four
   Three(1)
   in g(Three)
   Three(1)
   in g(Three)
 */
