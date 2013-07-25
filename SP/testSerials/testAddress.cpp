#include <iostream>
using namespace std;

int dog, cat, bird, fish;

void f(int pet)
{
    cout << "pet id number: " << pet << endl;
}

void g(int pet, int foo)
{
    f(pet);
}

int main()
{
    int i, j, k;
    cout << "(long)f(): " << (long) &f << endl;
    cout << "f(): " << &f << endl;
    cout << "(long)g(): " << (long) &g << endl;
    cout << "g(): " << &g << endl;
    cout << "(long)dog: " << (long) &dog << endl;
    cout << "dog: " << &dog << endl;
    cout << "(long)cat: " << (long) &cat << endl;
    cout << "cat: " << &cat << endl;
    cout << "(long)bird: " << (long) &bird << endl;
    cout << "bird: " << &bird << endl;
    cout << "(long)fish: " << (long) &fish << endl;
    cout << "fish: " << &fish << endl;
    cout << "(long)i: " << (long) &i << endl;
    cout << "i: " << &i << endl;
    cout << "(long)j: " << (long) &j << endl;
    cout << "j: " << &j << endl;
    cout << "(long)k: " << (long) &k << endl;
    cout << "k: " << &k << endl;
}
///:~

/* output
   (long)f(): 4440439792
   f(): 1
   (long)g(): 4440439888
   g(): 1
   (long)dog: 4440441032
   dog: 0x108abc0c8
   (long)cat: 4440441036
   cat: 0x108abc0cc
   (long)bird: 4440441040
   bird: 0x108abc0d0
   (long)fish: 4440441044
   fish: 0x108abc0d4
   (long)i: 140734945271684
   i: 0x7fff686b9f84
   (long)j: 140734945271680
   j: 0x7fff686b9f80
   (long)k: 140734945271676
   k: 0x7fff686b9f7c
 */
