/**
 * GlobalOperatorNew.cpp -- Global operator new overloading.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-23 [Friday, 235]
 *
 * Build:
 *   g++ GlobalOperatorNew.cpp -o GlobalOperatorNew
 */

#include <cstdio>
#include <cstdlib>

using namespace std;

void* operator new(size_t sz)
{
    printf("operator new: %ld Bytes\n", sz);
    void* m = malloc(sz);
    if(!m) puts("out of memory");
    return m;
}

void operator delete(void* m)
{
    puts("operator delete");
    free(m);
}

class S {
    int i[100];

    public:
        S() {
            puts("S::S()");
        }

        ~S() {
            puts("S::~S()");
        }
};
int main()
{
    puts("creating & destroying an int");
    int* p = new int(47);
    delete p;
    puts("creating & destroying an s");
    S* s = new S;
    delete s;
    puts("creating & destroying S[3]");
    S* sa = new S[3];
    delete[]sa;

    return 0;

} ///:~

/* Output:
   creating & destroying an int
   operator new: 4 Bytes
   operator delete
   creating & destroying an s
   operator new: 400 Bytes
   S::S()
   S::~S()
   operator delete
   creating & destroying S[3]
   operator new: 1208 Bytes
   S::S()
   S::S()
   S::S()
   S::~S()
   S::~S()
   S::~S()
   operator delete
 */
