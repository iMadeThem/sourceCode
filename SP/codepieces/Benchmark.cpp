/**
 * Benchmark.cpp -- Bench mark of calling.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-06 [Friday, 249]
 *
 * Build:
 *   g++ Benchmark.cpp -o Benchmark
 */

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>  // adjust alignment, cout.width, setw etc/
using namespace std;

template<typename Type>
double benchmark(Type const& t, size_t iterations)
{
    timeval a, b;
    gettimeofday(&a, 0);
    for(; iterations > 0; --iterations) {
        t.getArea();
    }
    gettimeofday(&b, 0);
    return (b.tv_sec * (unsigned int) 1e6 + b.tv_usec) - (a.tv_sec * (unsigned int) 1e6 + a.tv_usec);
}

struct Regular
{
    // class Regular
    // {
    //    public:
    Regular(size_t w, size_t h) : _width(w), _height(h) {}

    size_t getArea() const;

    size_t _width;
    size_t _height;
};

// The following line in another translation unit
// to avoid inlining
size_t Regular::getArea() const { return _width * _height; }

struct Base
{
    Base(size_t w, size_t h) : _width(w), _height(h) {}

    virtual size_t getArea() const = 0;

    size_t _width;
    size_t _height;
};

struct Derived : Base
{
    Derived(size_t w, size_t h) : Base(w, h) {}

    virtual size_t getArea() const;
};

// The following two functions in another translation unit to avoid inlining
size_t Derived::getArea() const  { return _width * _height; }

std::auto_ptr<Base> generateDerived()
{
    return std::auto_ptr<Base>(new Derived(3, 7));
}

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cerr << "Usage: %prog iterations\n";
        return 1;
    }

    Regular regular(3, 7);
    Derived derived_1(3, 7);
    std::auto_ptr<Base> derived_2 = generateDerived();

    double regTime = benchmark<Regular>(regular, atoi(argv[1]));
    double derTime_1 = benchmark<Base>(derived_1, atoi(argv[1]));
    double derTime_2 = benchmark<Base>(*derived_2, atoi(argv[1]));

    // right justified
    int KK = 21;
    std::cout.width(KK);
    std::cout << "Regular: " << regTime << std::endl;
    std::cout << std::setw(KK) << "Derived by itself: " << derTime_1 << std::endl;
    std::cout << std::setw(KK) << "Derived by auto_ptr: " << derTime_2 << std::endl;

    return 0;
} ///:~
