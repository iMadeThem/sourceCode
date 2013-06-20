#include <iostream>

/**
 * The size seems to be 0 since the class is empty without any data.
 * However, it should occupy some memory; otherwise, it cannot be accessed.
 * The size of memory is decided by compilers.
 */
class Test
{
};

class Test1 : public Test
{
//    char c;
    short s;
};

/**
 * The addresses for functions are irrelevant to instances, and compilers do not add any data in instances of this class.
 */
class Test2 : public Test
{
public:
    Test2(){};
    ~Test2(){}
};

/**
 * When a C++ compiler sees a virtual function inside a class,
 * it creates a virtual function table for the class and adds
 * a pointer to the table in each instance. A pointer in a 32-bit
 * machine occupies 4 bytes, so the result of sizeof is 4.
 * The result on a 64-bit machine is 8 because a pointer occupies 8 bytes there.
 */
class Test3 : public Test
{
public:
    virtual ~Test3(){}
};


int main()
{
    std::cout << "Size of empty class is " << sizeof(Test) << std::endl;
    std::cout << "Size of class with a short field, extended from empty class is " << sizeof(Test1) << std::endl;
    std::cout << "Size of class with constructor, extended from empty class is " << sizeof(Test2) << std::endl;
    std::cout << "Size of class with virtual destructor, extended from empty class is " << sizeof(Test3) << std::endl;
    return 0;
}
